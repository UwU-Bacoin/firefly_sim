#include <stdlib.h>
#include "firefly_sim.h"

population_t *population_create(int size)
{
    population_t *pop = malloc(sizeof(*pop) + (size * sizeof(firefly_t)));

    if (pop == NULL)
        return NULL;
    pop->individuals = (firefly_t *)(&pop[1]);
    pop->size = size;
    for (int i = 0; i < size; i++)
        firefly_init(pop->individuals + i);
    return pop;
}

void population_update(population_t *pop, int **neighbours)
{
    firefly_t *ff;

    if (pop == NULL || neighbours == NULL)
        return;
    for (int i = 0; i < pop->size; i++) {
        ff = pop->individuals + i;
        if (ff->energy > F_THRESHOLD) {
            neighbours_increment(neighbours[i], pop->individuals);
            ff->energy = 0;
        }
        firefly_increment(ff);
    }
}

void population_destroy(population_t *pop)
{
    if (pop != NULL)
        free(pop);
}
