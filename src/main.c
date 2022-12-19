#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>

#include "firefly.h"
#include "population.h"

__attribute__((constructor))
void init_random(void)
{
    srand48(time(NULL) + getpid());
}

int main(void)
{
    population_t pop = population_create(100);
    firefly_t *ff;

    for (int i = 0; i < 100; i++) {
        ff = pop[i];
        printf("Firefly %d: energy = %.3f, delta = %.3f\n", i, ff->energy, ff->delta);
    }
}
