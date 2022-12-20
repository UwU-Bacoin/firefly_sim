
#include <stddef.h>
#include "firefly.h"
#include "meadow.h"
#include "neighbours.h"

static int add_neighbour(meadow_t *meadow, int x, int y, int *nb)
{
    if (y < 0 || y >= meadow->height)
        return 0;
    if (x < 0 || x >= meadow->width)
        return 0;
    if (meadow->content[y][x] == FF_NULL)
        return 0;
    *nb = meadow->content[y][x];
    return 1;
}

static void compute_neighbours_firefly(
    meadow_t *meadow, int *neighbours, int x, int y)
{
    int current = 0;

    for (int cx = (x - FF_RADIUS); cx <= (x + FF_RADIUS); cx++) {
        for (int cy = (y - FF_RADIUS); cy <= (y + FF_RADIUS); cy++) {
            if (cx == x && cy == y)
                continue;
            current += add_neighbour(meadow, cx, cy, &neighbours[current]);
        }
    }
}

static int compute_neighbours_line(
    meadow_t *meadow, int **pop_neighbours, int y, int next)
{
    for (int x = 0; x < meadow->width; x++) {
        if (meadow->content[y][x] == FF_NULL)
            continue;
        compute_neighbours_firefly(meadow, pop_neighbours[next], x, y);
        next++;
    }
    return next;
}

int **neighbours_compute(meadow_t *meadow, int pop_count)
{
    int next = 0;
    int **pop_neighbours = neighbour_alloc(pop_count);

    if (pop_neighbours == NULL)
        return NULL;
    for (int y = 0; y < meadow->height; y++)
        next = compute_neighbours_line(meadow, pop_neighbours, y, next);
    return pop_neighbours;
}
