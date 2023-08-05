#include <stdio.h>
#include "firefly_sim.h"
#include "gif.h"

void simulate_meadow_steps(
    meadow_t *meadow, population_t *pop, int steps, int **neighbours)
{
    ge_GIF *gif = create_gif(meadow);
    float progress;

    for (int i = 0; i < steps; i++) {
        population_update(pop, neighbours);
        progress = (float) i / (float)steps;
        printf("Progress: %.3f\t\r", 100 * progress);
        add_frame(gif, meadow, pop, progress);
    }
    ge_close_gif(gif);
}
