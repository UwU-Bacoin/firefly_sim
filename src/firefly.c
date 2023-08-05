#include <stdlib.h>

#include "firefly_sim.h"

void firefly_init(firefly_t *firefly)
{
    if (firefly == NULL)
        return;
    firefly->energy = drand48() * 100;
    firefly->delta = drand48();
    if (firefly->delta < 0.01)
        firefly->delta += 0.01;
}

void firefly_increment(firefly_t *ff)
{
    ff->energy += ff->delta;
}
