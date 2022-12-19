#include <malloc.h>
#include "firefly.h"
#include "meadow.h"
#include "board.h"

int **neighbour_alloc(meadow_t *meadow, int pop_count)
{
    int **neighbours = board_alloc(pop_count, (FF_RADIUS * FF_RADIUS) - 1);

    if (neighbours == NULL)
        return NULL;
    for (int i = 0; i < pop_count; i++)
        for (int j = 0; j < (FF_RADIUS * FF_RADIUS) - 1; j++)
            neighbours[i][j] = FF_NULL;
    return neighbours;
}

void neighbour_free(int **neighbours, int pop_count)
{
    board_free(neighbours, pop_count);
}