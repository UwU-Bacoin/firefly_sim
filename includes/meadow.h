#ifndef MEADOW_H_
    #define MEADOW_H_

    #ifndef population_t
        #include "population.h"
    #endif

typedef struct meadow_s {
    int height;
    int width;
    board_t content;
} meadow_t;

meadow_t *meadow_init_empty(int height, int width);
void meadow_display(meadow_t *meadow, population_t *pop);
void meadow_destroy(meadow_t *meadow);
#endif
