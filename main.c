//MADE BY Gregor Alvin Oswald
#include "header.h"

int main(void)
{
    matrix_t base;
    init_matrix(&base);

    base.matrix[1][0] = 'O';
    base.matrix[0][1] = 'O';
    base.matrix[1][1] = 'O';

    print_matrix(&base);

    int eval = eval_matrix(base);
    printf("\n\n\n\n");
    printf("%d\n",eval);

    return 0;
}


