//MADE BY Gregor Alvin Oswald

#include "header.h"

ret_table_t search(matrix_t matrix, int idx, int jdx)
{
    //is_highest will determine if position is to be passed
    //from main, it is called with true, and from recursion allways false
    //this makes only the top level responsible for choosing move

    //size for array get smaller each recursion to save space
    //array saves returned values to determine which move to choose
    //depth = 0 at start, 1 for first computer move
    matrix.depth = matrix.depth + 1;
    int fule = how_full(&matrix);
    //9 spaces on the board - how full the board is, if 5 spaces are full, 9-5 = 4 shuold be the array lenght 
    ret_table_t weights[9-fule];
    //move determines mini max and what symbol to add to matrix for next level
    char move;
    move = matrix.depth % 2 == 0 ? 'X' : 'O';
    //count has amount of spaces to choose from
    int count = 0;
    for(int i = 0; i < 3; i++)     
    {
        for(int j = 0; j < 3; j++)
        { 
            //if space is full, skip
            if((matrix.matrix[i][j] != 'X') && (matrix.matrix[i][j] != 'O')) 
            {
                //if not, set space as move, run recursion, set space back to empty so next move isnt fuckedup (two Xs or Os in one move)
                matrix.matrix[i][j] = move;

                //NOTE: this is fix made later so original i,j comments talking about them being passed are wrong
                //root values hold return value that chooses next move
                int next_i = (matrix.depth == 1) ? i : idx;
                int next_j = (matrix.depth == 1) ? j : jdx;

                weights[count] = search(matrix,next_i, next_j);
                count++;
                matrix.matrix[i][j] = ' ';
            }
        }
    }
    //printf("weight array len = %d, fule = %d, count = %d\n", 9-fule, fule, count);
    //set values if game in end state
    //4 cuz first human move is 0, bot move is 1, that means 4 will be first possible depth to end game 
    ret_table_t ret;
    if(fule >= 4)
    {
        //-1 eval means nothing was found and possition is not to be evaluated yet, even in great enough depth
        //+-10 are values to taken into cosideraton when evaluating
        int weight = eval_matrix(matrix);
        if(weight != -1)
        {
            ret.depth_reached = matrix.depth;
            ret.weight = weight;
            ret.idx = idx;
            ret.jdx = jdx;
            return ret;
        }        
    }

    //here will be sorting and returning in the higher layers
    choose_move(weights, count);
    if(matrix.depth == 1)
    {
        for(int i = 0; i < count; i++)
        {
            printf("idx = %d, jdx = %d, depth = %d, weight = %d\n", weights[i].idx, weights[i].jdx, weights[i].depth_reached, weights[i].weight);
        }
    }
    //ternary operator for return, if human player, choose min, if computer, choose max
    return (move == 'X') ? weights[count - 1] :  weights[0];
}