#include <stdio.h>
#include "firefly_sim.h"

char firefly_symbol(double energy_level)
{
    return (energy_level > F_THRESHOLD) ? '*' : '.';
}

void firefly_display(double energy_level, bool verbose)
{
    printf("%c", firefly_symbol(energy_level));
    if (verbose)
        printf(" (%f)", energy_level);
    printf("\n");
}
