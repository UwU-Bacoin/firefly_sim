#include <stdlib.h>
#include "firefly.h"
#include "meadow.h"
#include "board.h"

int **neighbour_alloc(meadow_t *meadow, int pop_count)
{
    int **neighbours = board_alloc(pop_count, FF_RADIUS_MAX_IN);

    if (neighbours == NULL)
        return NULL;
    for (int i = 0; i < pop_count; i++)
        for (int j = 0; j < (FF_RADIUS_MAX_IN); j++)
            neighbours[i][j] = FF_NULL;
    return neighbours;
}

void neighbours_increment(int const *neighbours, firefly_t **pop)
{
    int ff_idx = 0;

    while (neighbours[ff_idx] != FF_NULL) {
        pop[ff_idx]->energy += FF_INTAKE;
        ff_idx++;
    }
}

void neighbour_free(int **neighbours, int pop_count)
{
    board_free(neighbours, pop_count);
}
