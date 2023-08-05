#include <stdlib.h>
#include "firefly_sim.h"

int **neighbour_alloc(int pop_count)
{
    int **neighbours = board_alloc(pop_count, FF_RADIUS_MAX_IN);

    if (neighbours == NULL)
        return NULL;
    for (int y = 0; y < pop_count; y++)
        for (int x = 0; x < (FF_RADIUS_MAX_IN); x++)
            neighbours[y][x] = FF_NULL;
    return neighbours;
}

void neighbours_increment(int const *neighbours, firefly_t *pop)
{
    int ff_idx = 0;

    while (neighbours[ff_idx] != FF_NULL) {
        (pop + ff_idx)->energy += FF_INTAKE;
        ff_idx++;
    }
}

void neighbour_free(int **neighbours, int pop_count)
{
    board_free(neighbours, pop_count);
}
