#ifndef SIMULATION_H_
    #define SIMULATION_H_

    #ifndef MEADOW_H_
        #include "meadow.h"
    #endif

void simulate_meadow_steps(
    meadow_t *meadow, population_t *pop, int steps, int **neighbours);
#endif
