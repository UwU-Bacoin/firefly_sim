#include <stdbool.h>
#include <stdlib.h>

#include "firefly.h"

int main(void)
{
    int energy = rand() % 100;

    firefly_display(energy, true);
    energy = 50;
    firefly_display(energy, true);
    energy = 150;
    firefly_display(energy, true);
    energy = 250;
    firefly_display(energy, true);
}
