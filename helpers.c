//MADE BY Gregor Alvin Oswald

#include "header.h"

//prints game state on stdout
void print_matrix(matrix_t *matrix)
{
    printf("%c | %c | %c\n", matrix->matrix[0][0], matrix->matrix[0][1], matrix->matrix[0][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", matrix->matrix[1][0], matrix->matrix[1][1], matrix->matrix[1][2]);
    printf("---------\n");
    printf("%c | %c | %c\n", matrix->matrix[2][0], matrix->matrix[2][1], matrix->matrix[2][2]);
}

//sets all squares to " " (empty space)
void init_matrix(matrix_t *matrix)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix->matrix[i][j] = ' ';
        }
    }
}