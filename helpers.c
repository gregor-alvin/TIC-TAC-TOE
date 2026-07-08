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
    matrix->depth = 0;
}

//runs through the matrix to see if its full
bool is_full(matrix_t* matrix)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(matrix->matrix[i][j] == ' ') return false;
        }
    }
    return true;
}

int how_full(matrix_t *matrix)
{
    int count = 0;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if((matrix->matrix[i][j] == 'X') || (matrix->matrix[i][j] == 'O')) count++;
        }
    }
    return count;
}


//swaps values
//idx and jdx stay the same, im passing them through every layer cuz im stupid and dont know rn how else to save first move, cuz thaths what ill pass
void swap(ret_table_t *a, ret_table_t *b)
{
    ret_table_t x;
    x.depth_reached = a->depth_reached;
    x.weight = a->weight;
    a->depth_reached = b->depth_reached;
    a->weight = b->weight;
    b->depth_reached = x.depth_reached;
    b->weight = x.weight;   
}



//sort, smallest first, biggest last, minimax determines from which end to take
void choose_move(ret_table_t *arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(i >= j) continue;
            if(arr[i]->weight < arr[j]->weight) swap(arr[i], arr[j]);
        }
    }
}