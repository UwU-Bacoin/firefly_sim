#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "simulation.h"
#include "population.h"
#include "meadow.h"
#include "neighbours.h"

__attribute__((constructor))
void init_random(void)
{
    srand48(time(NULL) + getpid());
    srand(time(NULL) + getpid());
}

int main(void)
{
    population_t *pop = population_create(10);
    meadow_t *meadow = meadow_init(5, 5, pop);
    int **neighbours = neighbours_compute(meadow, pop->size);

    simulate_meadow_steps(meadow, pop, 10000, neighbours);
    population_destroy(pop);
    meadow_destroy(meadow);
    neighbour_free(neighbours, pop->size);
}
