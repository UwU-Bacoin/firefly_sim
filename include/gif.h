#ifndef GIF_H_
    #define GIF_H_

    #include "firefly_sim.h"
    #include "gifenc.h"

ge_GIF *create_gif(meadow_t *meadow);
void add_frame(
    ge_GIF *gif, meadow_t *meadow, population_t *pop,
    float progress);
#endif
