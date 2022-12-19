#include <stdio.h>

#include "population.h"
#include "firefly.h"
#include "meadow.h"

static void meadow_display_firefly(int ff_id, population_t *pop)
{
    firefly_t *ff = pop->individuals[ff_id];

    printf("%c", firefly_symbol(ff->energy));
}

static void meadow_display_line(meadow_t *meadow, population_t *pop, int line)
{
    printf("#");
    for (int i = 0; i < meadow->width; i++) {
        if (meadow->content[line][i] != FF_NULL) {
            meadow_display_firefly(meadow->content[0][i], pop);
        } else {
            printf(" ");
        }
    }
    printf("#\n");
}

void meadow_display(meadow_t *meadow, population_t *pop)
{
    for (int i = 0; i < meadow->height; i++)
        printf("#");
    printf("\n");
    for (int i = 0; i < meadow->height; i++)
        meadow_display_line(meadow, pop, i);
    for (int i = 0; i < meadow->height; i++)
        printf("#");
    printf("\n");
}
