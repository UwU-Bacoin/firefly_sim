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
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            meadow->content[y][x] = FF_NULL;
    return meadow;
}

meadow_t *meadow_init(int height, int width, population_t *pop)
{
    int x;
    int y;
    int pop_n;
    meadow_t *meadow;

    if (pop == NULL)
        return NULL;
    meadow = meadow_init_empty(height, width);
    if (meadow == NULL)
        return NULL;
    pop_n = pop->size;
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

void meadow_destroy(meadow_t *meadow)
{
    if (meadow == NULL)
        return;
    board_free(meadow->content, meadow->height);
    free(meadow);
}
