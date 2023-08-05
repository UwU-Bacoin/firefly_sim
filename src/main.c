#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "firefly_sim.h"

__attribute__((constructor))
__attribute__((used))
void init_random(void)
{
    srand48(time(NULL) + getpid());
    srand(time(NULL) + getpid());
}

int main(void)
{
    population_t *pop = population_create(100);
    meadow_t *meadow = meadow_init(128, 128, pop);
    int **neighbours = neighbours_compute(meadow, pop->size);

    simulate_meadow_steps(meadow, pop, 1000, neighbours);
    meadow_destroy(meadow);
    neighbour_free(neighbours, pop->size);
    population_destroy(pop);
}
