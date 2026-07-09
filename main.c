//MADE BY Gregor Alvin Oswald
#include "header.h"

int main(void)
{
    matrix_t matrix;    
    init_matrix(&matrix);

    clear_terminal();
    for(int i = 0; i < 9; i++)
    {
        print_matrix(&matrix);
        int move;
        usleep(1000);
        scanf("%d", &move);
        if((move <= 0) || (move >= 10))
        {
            printf("again pls\n");
            scanf("%d\n", &move);
            if((move <= 0) || (move >= 10))
            {
                printf("OK, U DONE\n");
                return 0;
            }
        }
        translate_move(&matrix, move);


        
        //run simulation, 0,0 are dum,y values, only pc needs them
        ret_table_t pc = search(matrix, 0, 0);
        matrix.matrix[pc.idx][pc.jdx] = 'O';
        

        int x = eval_matrix(matrix);
        if(x != -1)
        {
            clear_terminal();
            print_matrix(&matrix);
            if(x == DEF) printf("YOU WON\n");
            if(x == WIN) printf("I WON\n");
            if(x == DRAW) printf("DRAW\n");
            printf("game ended\n");
            return 1;
        }
        clear_terminal();
    }
    return 1;
}