#include <stdlib.h>

#include "firefly.h"

firefly_t *firefly_init(void)
{
    firefly_t *firefly = malloc(sizeof(firefly_t));
    firefly->energy = drand48() * 100;
    firefly->delta = drand48();
    return firefly;
}

__attribute__((nonnull(1)))
void firefly_increment(firefly_t *ff)
{
    ff->energy += ff->delta;
}

__attribute__((nonnull(1)))
void firefly_destroy(firefly_t *firefly)
{
    free(firefly);
}
