#include <stdlib.h>
#include "firefly_sim.h"

static
population_t *population_alloc_failed(population_t *pop, int i)
{
    for (int j = i - 1; j >= 0; j--)
        free(pop->individuals[j]);
    free(pop->individuals);
    free(pop);
    return NULL;
}

population_t *population_create(int size)
{
    population_t *pop = malloc(sizeof(population_t));

    if (pop == NULL)
        return NULL;
    pop->size = size;
    pop->individuals = malloc(size * sizeof(firefly_t *));
    if (pop->individuals == NULL) {
        free(pop);
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        pop->individuals[i] = firefly_init();
        if (pop->individuals[i] == NULL)
            return population_alloc_failed(pop, i);
    }
    return pop;
}

void population_destroy(population_t *pop)
{
    if (pop == NULL)
        return;
    population_alloc_failed(pop, pop->size);
}

void population_update(population_t *pop, int **neighbours)
{
    firefly_t *ff;

    if (pop == NULL || neighbours == NULL)
        return;
    for (int i = 0; i < pop->size; i++) {
        ff = pop->individuals[i];
        if (ff->energy > F_THRESHOLD) {
            neighbours_increment(neighbours[i], pop->individuals);
            ff->energy = 0;
        }
        firefly_increment(ff);
    }
}
