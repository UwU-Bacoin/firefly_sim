#include <malloc.h>
#include "firefly.h"
#include "population.h"

population_t population_create(int size)
{
    population_t pop = malloc(size * sizeof(firefly_t *));
    if (pop == NULL)
        return NULL;
    for (int i = 0; i < size; i++)
        pop[i] = firefly_init();
    return pop;
}
