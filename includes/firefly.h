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

char firefly_symbol(int energy_level);
void firefly_display(int energy_level, bool verbose);
#endif
