#ifndef MEADOW_H_
    #define MEADOW_H_

typedef int **meadow_t;

meadow_t meadow_init_empty(int height, int width);
void meadow_destroy(meadow_t meadow);
#endif
