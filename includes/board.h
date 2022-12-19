#ifndef BOARD_H_
    #define BOARD_H_

int **board_alloc(int height, int width);
void board_free(int **board, int height);
#endif
