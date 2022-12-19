#include <malloc.h>
#include "firefly.h"
#include "population.h"

__attribute__((nonnull(1)))
static population_t *population_alloc_failed(population_t *pop, int i)
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

__attribute__((nonnull(1)))
void population_destroy(population_t *pop)
{
    population_alloc_failed(pop, pop->size);
}
