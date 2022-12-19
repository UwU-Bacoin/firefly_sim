#ifndef POPULATION_H_
    #define POPULATION_H_

typedef struct population_s {
    int size;
    firefly_t **individuals;
} population_t;

population_t *population_create(int size);
population_t *population_alloc_failed(population_t *pop, int i);
void population_destroy(population_t *pop);
#endif
