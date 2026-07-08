//MADE BY Gregor Alvin Oswald
#include "header.h"

int main(void)
{
    matrix_t matrix;
    
    init_matrix(&matrix);

    print_matrix(&matrix);

    int eval = eval_matrix(matrix);
    printf("\n\n\n\n");
    printf("%d\n",eval);

    return 0;
}


