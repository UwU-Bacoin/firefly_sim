#ifndef FIREFLY_SIM_H
    #define FIREFLY_SIM_H

    #define F_THRESHOLD (25)
    #define FF_NULL (-1)
    #define FF_INTAKE (100)

    #define FF_RADIUS (2)
    #define FF_PERIMETER (FF_RADIUS * 2 + 1)
    #define FF_RADIUS_MAX_IN (FF_PERIMETER * FF_PERIMETER)

    #include <stdbool.h>

typedef struct meadow_s {
    int height;
    int width;
    int **content;
} meadow_t;

typedef struct firefly {
    double energy;
    double delta;
} firefly_t;

typedef struct population_s {
    int size;
    firefly_t **individuals;
} population_t;

firefly_t *firefly_init(void);

char firefly_symbol(double energy_level);
void firefly_increment(firefly_t *ff);

int **board_alloc(int height, int width);
void board_free(int **board, int height);

meadow_t *meadow_init_empty(int height, int width);
meadow_t *meadow_init(int height, int width, population_t *pop);
void meadow_destroy(meadow_t *meadow);

int **neighbour_alloc(int pop_count);
int **neighbours_compute(meadow_t *meadow, int pop_count);
void neighbours_increment(int const *neighbours, firefly_t **pop);
void neighbour_free(int **neighbours, int pop_count);

population_t *population_create(int size);
void population_update(population_t *pop, int **neighbours);
void population_destroy(population_t *pop);

void simulate_meadow_steps(meadow_t *meadow, population_t *pop, int steps, int **neighbours);
#endif
