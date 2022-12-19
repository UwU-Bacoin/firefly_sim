
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
    meadow_t *meadow, int *neighbours, int i, int j)
{
    int next = 0;

    for (int cx = i - FF_RADIUS; cx <= i + FF_RADIUS; cx++)
        for (int cy = j - FF_RADIUS; cy <= j + FF_RADIUS; cy++)
            next += add_neighbour(meadow, cx, cy, &neighbours[next]);
}

static int compute_neighbours_line(
    meadow_t *meadow, int **pop_neighbours, int i)
{
    int next = 0;

    for (int j = 0; j < meadow->height; j++) {
        if (meadow->content[i][j] == FF_NULL)
            continue;
        compute_neighbours_firefly(meadow, pop_neighbours[next], i, j);
        next++;
    }
    return next;
}

int **neighbours_compute(meadow_t *meadow, int pop_count)
{
    int next = 0;
    int **pop_neighbours = neighbour_alloc(meadow, pop_count);

    if (pop_neighbours == NULL)
        return NULL;
    for (int i = 0; i < meadow->width; i++)
        next += compute_neighbours_line(meadow, pop_neighbours, i);
    return pop_neighbours;
}
