#ifndef NEIGHBOURS_H_
    #define NEIGHBOURS_H_

    #ifndef meadow_t
        #include "meadow.h"
    #endif

int **neighbour_alloc(meadow_t *meadow, int pop_count);
int **neighbours_compute(meadow_t *meadow, int pop_count);
void neighbours_increment(int const *neighbours, firefly_t **pop);
void neighbour_free(int **neighbours, int pop_count);
#endif
