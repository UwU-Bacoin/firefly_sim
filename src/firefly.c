#include <stdio.h>
#include <stdbool.h>
#include "firefly.h"

char firefly_symbol(int energy_level)
{
    return (energy_level > F_THRESHOLD) ? '*': ' ';
}

void firefly_display(int energy_level, bool verbose)
{
    printf("%c", firefly_symbol(energy_level));
    if (verbose)
        printf(" (%d)", energy_level);
    printf("\n");
}
