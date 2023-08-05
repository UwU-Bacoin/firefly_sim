#include "gif.h"
#include "firefly_sim.h"

ge_GIF *create_gif(meadow_t *meadow)
{
    uint8_t palette[] = {
        0x0F, 0x10, 0x17,
        0x35, 0x54, 0x2E,
        0xCF, 0xFF, 0x64,
        0xED, 0xDC, 0xBA,
    };

    return ge_new_gif(
        "meadow.gif",
        meadow->width, meadow->height + 1,
        palette, 2, -1, 0
    );
}

static int resolve_col(meadow_t *meadow, population_t *pop, int i, int j)
{
    int ff_id = meadow->content[i][j];

    if (ff_id == FF_NULL)
        return 0;
    return 1 + (pop->individuals[ff_id]->energy > F_THRESHOLD);
}

void add_frame(ge_GIF *gif, meadow_t *meadow, population_t *pop, float progress)
{
    for (int i = 0; i < meadow->height; i++)
        for (int j = 0; j < meadow->width; j++)
            gif->frame[i * meadow->width + j] = resolve_col(meadow, pop, i, j);
    for (int j = 0; j < meadow->width; j++)
        gif->frame[meadow->height * meadow->width + j] = 0;
    for (int j = 0; j < (int)(progress * (float)meadow->width); j++)
        gif->frame[meadow->height * meadow->width + j] = 3;
    ge_add_frame(gif, 10);
}
