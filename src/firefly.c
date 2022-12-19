#include <stdio.h>
#include <stdbool.h>

#include "firefly.h"

char firefly_symbol(double energy_level)
{
    return (energy_level > F_THRESHOLD) ? '*': ' ';
}

void firefly_display(double energy_level, bool verbose)
{
    printf("%c", firefly_symbol(energy_level));
    if (verbose)
        printf(" (%f)", energy_level);
    printf("\n");
}


double firefly_increment(double energy_level, double delta_energy)
{
    return energy_level + delta_energy;
}
