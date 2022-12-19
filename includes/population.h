#ifndef POPULATION_H_
    #define POPULATION_H_

    #ifndef firefly_t
        #include "firefly.h"
    #endif

typedef struct population_s {
    int size;
    firefly_t **individuals;
} population_t;

population_t *population_create(int size);
void population_update(population_t *pop);
void population_destroy(population_t *pop);
#endif
