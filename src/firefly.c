#include <stdlib.h>

#include "firefly_sim.h"

firefly_t *firefly_init(void)
{
    firefly_t *firefly = malloc(sizeof(firefly_t));

    if (firefly == NULL)
        return NULL;
    firefly->energy = drand48() * 100;
    firefly->delta = drand48();
    if (firefly->delta < 0.01)
        firefly->delta += 0.01;
    return firefly;
}

void firefly_increment(firefly_t *ff)
{
    ff->energy += ff->delta;
}

void firefly_destroy(firefly_t *firefly)
{
    free(firefly);
}
