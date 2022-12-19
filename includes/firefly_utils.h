#ifndef FIREFLY_UTILS_H_
    #define FIREFLY_UTILS_H_

    #ifndef bool
        #include <stdbool.h>
    #endif

char firefly_symbol(double energy_level);
void firefly_display(double energy_level, bool verbose);
double firefly_increment(double energy_level, double delta_energy);
#endif
