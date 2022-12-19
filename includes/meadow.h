#ifndef MEADOW_H_
    #define MEADOW_H_

    #ifndef population_t
        #include "population.h"
    #endif

typedef struct meadow_s {
    int height;
    int width;
    int **content;
} meadow_t;

meadow_t *meadow_init_empty(int height, int width);
meadow_t *meadow_init(int height, int width, population_t *pop);
void meadow_display(meadow_t *meadow, population_t *pop);
void meadow_destroy(meadow_t *meadow);
#endif
