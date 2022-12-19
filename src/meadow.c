#include <malloc.h>
#include "board.h"
#include "meadow.h"
#include "firefly.h"

meadow_t *meadow_init_empty(int height, int width)
{
    meadow_t *meadow = malloc(sizeof(meadow_t));

    if (meadow == NULL)
        return NULL;
    meadow->height = height;
    meadow->width = width;
    meadow->content = board_alloc(height, width);
    if (meadow->content == NULL) {
        free(meadow);
        return NULL;
    }
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            meadow->content[i][j] = FF_NULL;
    return meadow;
}

void meadow_destroy(meadow_t *meadow)
{
    board_free(meadow->content, meadow->height);
    free(meadow);
}
