#include <malloc.h>
#include "board.h"

board_t board_alloc(int height, int width)
{
    board_t board = malloc(height * sizeof(int *));

    if (board == NULL)
        return NULL;
    for (int i = 0; i < height; i++) {
        board[i] = malloc(width * sizeof(int));
        if (board[i] == NULL)
            return board_alloc_failed(board, i);
    }
    return board;
}

board_t board_alloc_failed(board_t board, int i)
{
    for (int j = i; j > 0; j--)
        free(board[j]);
    free(board);
    return NULL;
}

void board_free(board_t board, int height)
{
    board_alloc_failed(board, height);
}
