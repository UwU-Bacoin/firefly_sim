#ifndef SIMULATION_H_
    #define SIMULATION_H_

    #ifndef MEADOW_H_
        #include "meadow.h"
    #endif

void simulate_firefly_steps(int steps);
void simulate_firefly_flashes(int flash_count);
void simulate_meadow_steps(
    meadow_t *meadow, population_t *pop, int steps, int **neighbours);
#endif
