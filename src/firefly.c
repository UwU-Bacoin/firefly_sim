#include <stdlib.h>

#include "firefly.h"

firefly_t *firefly_init(void)
{
    firefly_t *firefly = malloc(sizeof(firefly_t));
    firefly->energy = drand48() * 100;
    firefly->delta = drand48();
    return firefly;
}

void firefly_destroy(firefly_t *firefly)
{
    free(firefly);
}
