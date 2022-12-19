#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "population.h"
#include "meadow.h"

__attribute__((constructor))
void init_random(void)
{
    srand48(time(NULL) + getpid());
}

int main(void)
{
    population_t *pop = population_create(100);
    meadow_t *meadow = meadow_init(15, 15, pop);

    meadow_display(meadow, pop);
    population_destroy(pop);
    meadow_destroy(meadow);
}
