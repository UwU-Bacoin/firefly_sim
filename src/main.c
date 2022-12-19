#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "firefly.h"

int main(void)
{
    srand48(time(NULL) + getpid());
    double energy = drand48() * 100;
    double delta_energy = drand48();

    for (int i = 0; i < 50; i++) {
        energy = firefly_increment(energy, delta_energy);
        firefly_display(energy, true);
    }
}
