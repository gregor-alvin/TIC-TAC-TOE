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
            print_statement();
        }
        else 
        {
            //prints matrix + helper matrix
            print_matrix(&matrix);
            print_statement();
        }

        int move;
        scanf("%d", &move);
        ////////////////////////////////////////
        //HERE ILL NEED TO PASS move TO GUI
        ////////////////////////////////////////

        //if move is not valid, try again
        bool is_move_ok = translate_move(&matrix, move);
        int attempts = 1;
        while(!is_move_ok && attempts < 3)
        {
            printf("\nmove invalid\n");
            printf("again pls\n");
            scanf("%d", &move);
            is_move_ok = translate_move(&matrix, move);
            attempts++;
        }
        if(!is_move_ok)
        {
            clear_terminal();
            printf("invalid move\n U DONE\n");
            return 0;
        }

        int x = eval_matrix(matrix);
        if(x != -1)
        {
            clear_terminal();
            print_matrix(&matrix);
            if(x == DEF) printf("YOU WON\n");
            if(x == WIN) printf("I WON\n");
            if(x == DRAW) printf("DRAW\n");
            printf("\ngame ended\n");
            return 1;
        }

        //run simulation, 0,0 are dummy values, only pc needs them
        x = eval_matrix(matrix);
        if(x == -1)
        {
            ret_table_t pc = search(matrix, 0, 0);
            matrix.matrix[pc.idx][pc.jdx] = 'O';
            clear_terminal();
            print_matrix(&matrix);
            ////////////////////////////////////////////////
            //HERE ILL NEED TO PASS pc.idx AND pc.jdx TO GUI
            ////////////////////////////////////////////////
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