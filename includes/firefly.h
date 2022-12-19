#ifndef FIREFLY_H_
    #define FIREFLY_H_

    #define F_THRESHOLD 100
    #define F_NULL -1;

    #ifndef bool
        #include <stdbool.h>
    #endif

typedef struct firefly {
    double current_energy;
    double delta_energy;
} firefly_t;

firefly_t *firefly_init(void);
void firefly_destroy(firefly_t *firefly);
#endif
