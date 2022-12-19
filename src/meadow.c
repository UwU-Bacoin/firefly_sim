#include <malloc.h>
#include <stdlib.h>
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

__attribute__((nonnull(1, 2)))
static meadow_t *meadow_populate(meadow_t *meadow, population_t *pop)
{
    int x;
    int y;
    int pop_n = pop->size;

    while (pop_n) {
        x = rand() % meadow->width;
        y = rand() % meadow->height;
        if (meadow->content[y][x] == FF_NULL) {
            meadow->content[y][x] = pop->size - pop_n;
            pop_n--;
        }
    }
    return meadow;
}

__attribute__((nonnull(3)))
meadow_t *meadow_init(int height, int width, population_t *pop)
{
    meadow_t *meadow = meadow_init_empty(height, width);

    if (meadow == NULL)
        return NULL;
    return meadow_populate(meadow, pop);
}

__attribute__((nonnull(1)))
void meadow_destroy(meadow_t *meadow)
{
    board_free(meadow->content, meadow->height);
    free(meadow);
}
