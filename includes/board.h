#ifndef BOARD_H_
    #define BOARD_H_

typedef int **board_t;

board_t board_alloc(int height, int width);

board_t board_alloc_failed(board_t board, int i);
void board_free(board_t board, int height);
#endif
