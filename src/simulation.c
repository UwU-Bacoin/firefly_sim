#include "firefly.h"
#include "population.h"
#include "meadow.h"

void simulate_firefly_steps(int steps)
{
    firefly_t *ff = firefly_init();

    if (!ff)
        return;
    for (int i = 0; i < steps; i++) {
        firefly_increment(ff);
        firefly_display(ff->energy, true);
        if (ff->energy > F_THRESHOLD)
            ff->energy = 0;
    }
    firefly_destroy(ff);
}

void simulate_firefly_flashes(int flash_count)
{
    firefly_t *ff = firefly_init();
    int remaining_flashes = flash_count;

    if (!ff)
        return;
    while (remaining_flashes) {
        firefly_increment(ff);
        firefly_display(ff->energy, true);
        if (ff->energy > F_THRESHOLD) {
            ff->energy = 0;
            remaining_flashes--;
        }
    }
    firefly_destroy(ff);
}

void simulate_meadow_steps(meadow_t *meadow, population_t *pop, int steps)
{
    for (int i = 0; i < steps; i++) {
        population_update(pop);
        meadow_display(meadow, pop);
    }
}
