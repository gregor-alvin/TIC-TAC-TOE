//MADE BY Gregor Alvin Oswald

#ifndef header
#define header
//incldues
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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

void print_matrix(matrix_t *);

void init_matrix(matrix_t *);

int eval_matrix(matrix_t);

int main(void);


#endif