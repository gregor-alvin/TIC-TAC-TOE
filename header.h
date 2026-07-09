//MADE BY Gregor Alvin Oswald

#ifndef header
#define header
//incldues
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

//defs 
//win lose returns for eval
#define WIN 10
#define DEF -10
#define DRAW 0


//structs
//matrix holds data for game state in 3x3 char array
//depth holds depth of calculation 
typedef struct {
    char matrix[3][3];
    int depth;
} matrix_t;

//info passing between levels of recursion, holds weight of branch and position of next move
typedef struct {
    int idx;
    int jdx;
    int weight;
    int depth_reached;
} ret_table_t;


//helpers
void print_matrix(matrix_t *);

void init_matrix(matrix_t *);

bool is_full(matrix_t *);

int how_full(matrix_t *);

void choose_move(ret_table_t [], int);

void swap(ret_table_t *, ret_table_t *);

void translate_move(matrix_t *, int);

void clear_terminal(void);

//eval
int eval_matrix(matrix_t);

//search
ret_table_t search(matrix_t, int, int);

//main
int main(void);


#endif