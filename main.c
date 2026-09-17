//MADE BY Gregor Alvin Oswald
#include "header.h"

int main(void)
{
    matrix_t matrix;    
    init_matrix(&matrix);

    //game starts
    clear_terminal();

    printf("choose mode, human starts(1) or pc starts(0)\n");
    int mode;
    scanf("%d", &mode);
    if((mode != 1) && (mode != 0))
    {
        printf("wrong number, ill just assume u should start\n");
        mode = 1;
    }

    bool first_cycle = false;
    
    for(int i = 0; i < 5; i++)
    {
        //prints matrix + helper matrix
        print_matrix(&matrix);

        //faked pc start 
        //since its optimal to start in a corner, and with rotations it basicly does not matter, we can randomly choose a corner
        if(mode == 0 && !first_cycle)
        {
            srand(time(NULL));
            int rand_pos = (rand() % 4) + 1;
            if(rand_pos == 1) matrix.matrix[0][0] = 'O';
            if(rand_pos == 2) matrix.matrix[0][2] = 'O';
            if(rand_pos == 3) matrix.matrix[2][0] = 'O';
            if(rand_pos == 4) matrix.matrix[2][2] = 'O';
            first_cycle = true;
            print_matrix(&matrix);
        }

        int move;
        usleep(1000);
        printf("human turn\n");
        scanf("%d", &move);
        //if move is not valid, try again
        bool is_move_ok = translate_move(&matrix, move);
        if(!is_move_ok)
        {
            printf("\nmove invalid\n");
            printf("again pls\n");
            scanf("%d", &move);
            is_move_ok = translate_move(&matrix, move);
            if(!is_move_ok)
            {
                printf("\nmove invalid\n");
                printf("again pls\n");
                scanf("%d", &move);
                is_move_ok = translate_move(&matrix, move);
                if(!is_move_ok)
                {
                    printf("invalid move\n U DONE\n");
                }
            }
        }

        printf("passed to pc:\n");
        print_matrix(&matrix);
        printf("pc calcul\n");        
        //run simulation, 0,0,0,0 are dummy values, only pc needs them
        int x = eval_matrix(matrix);
        if(x == -1)
        {
            ret_table_t pc = search(matrix, 0, 0);
            printf("\npc chose:\n");
            printf("idx = %d, jdx = %d, depth = %d, weight = %d\n", pc.idx, pc.jdx, pc.depth_reached, pc.weight);
            printf("idx = %d, jdx = %d\n", pc.idx, pc.jdx);
            matrix.matrix[pc.idx][pc.jdx] = 'O';
        }

        x = eval_matrix(matrix);
        if(x != -1)
        {
            //clear_terminal();
            print_matrix(&matrix);
            if(x == DEF) printf("YOU WON\n");
            if(x == WIN) printf("I WON\n");
            if(x == DRAW) printf("DRAW\n");
            printf("game ended\n");
            return 1;
        }
        //clear_terminal();
    }
    return 1;
}