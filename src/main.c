#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "simulation.h"
#include "population.h"
#include "meadow.h"

__attribute__((constructor))
void init_random(void)
{
    srand48(time(NULL) + getpid());
    srand(time(NULL) + getpid());
}

int main(void)
{
    population_t *pop = population_create(4);
    meadow_t *meadow = meadow_init(3, 3, pop);

    simulate_meadow_steps(meadow, pop, 200);
    population_destroy(pop);
    meadow_destroy(meadow);
}
