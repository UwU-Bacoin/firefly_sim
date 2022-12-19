#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "simulation.h"

int main(void)
{
    srand48(time(NULL) + getpid());
    simulate_firefly_steps(100);
}
