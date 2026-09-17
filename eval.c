//MADE BY Gregor Alvin Oswald

#include "header.h"

int eval_matrix(matrix_t matrix)
{
    //find if anyone won
    //rows
    if(((matrix.matrix[0][0] == 'O') && (matrix.matrix[0][1] == 'O') && (matrix.matrix[0][2] == 'O')) ||
        ((matrix.matrix[1][0] == 'O') && (matrix.matrix[1][1] == 'O') && (matrix.matrix[1][2] == 'O')) ||
        ((matrix.matrix[2][0] == 'O') && (matrix.matrix[2][1] == 'O') && (matrix.matrix[2][2] == 'O')) ||
        //columns
        ((matrix.matrix[0][0] == 'O') && (matrix.matrix[1][0] == 'O') && (matrix.matrix[2][0] == 'O')) ||
        ((matrix.matrix[0][1] == 'O') && (matrix.matrix[1][1] == 'O') && (matrix.matrix[2][1] == 'O')) ||
        ((matrix.matrix[0][2] == 'O') && (matrix.matrix[1][2] == 'O') && (matrix.matrix[2][2] == 'O')) ||
        //diagonals
        ((matrix.matrix[0][0] == 'O') && (matrix.matrix[1][1] == 'O') && (matrix.matrix[2][2] == 'O')) ||
        ((matrix.matrix[2][0] == 'O') && (matrix.matrix[1][1] == 'O') && (matrix.matrix[0][2] == 'O'))
        )
        {
            return WIN;
        }

    //defeat
    if(((matrix.matrix[0][0] == 'X') && (matrix.matrix[0][1] == 'X') && (matrix.matrix[0][2] == 'X')) ||
        ((matrix.matrix[1][0] == 'X') && (matrix.matrix[1][1] == 'X') && (matrix.matrix[1][2] == 'X')) ||
        ((matrix.matrix[2][0] == 'X') && (matrix.matrix[2][1] == 'X') && (matrix.matrix[2][2] == 'X')) ||
        //columns
        ((matrix.matrix[0][0] == 'X') && (matrix.matrix[1][0] == 'X') && (matrix.matrix[2][0] == 'X')) ||
        ((matrix.matrix[0][0] == 'X') && (matrix.matrix[1][1] == 'X') && (matrix.matrix[2][1] == 'X')) ||
        ((matrix.matrix[0][0] == 'X') && (matrix.matrix[1][2] == 'X') && (matrix.matrix[2][2] == 'X')) ||
        //diagonals
        ((matrix.matrix[0][0] == 'X') && (matrix.matrix[1][1] == 'X') && (matrix.matrix[2][2] == 'X')) ||
        ((matrix.matrix[2][0] == 'X') && (matrix.matrix[1][1] == 'X') && (matrix.matrix[0][2] == 'X'))
        )
        {
            return DEF;
        }
    //TODO not sure yet how to return none yet, proly will set it sum constant
    //draws
    bool board_full = true;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix.matrix[i][j] == ' ') board_full = false;
        }
    }
    if(board_full)
    {
        return DRAW;
    } 
    return -1;
}