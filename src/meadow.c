#include <malloc.h>
#include "meadow.h"
#include "firefly.h"

meadow_t meadow_init_empty(int height, int width)
{
    meadow_t meadow = malloc(height * width * sizeof(int));

    if (meadow == NULL)
        return NULL;

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            meadow[i][j] = F_NULL;
    return meadow;
}

void meadow_destroy(meadow_t meadow)
{
    free(meadow);
}
