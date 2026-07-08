//MADE BY Gregor Alvin Oswald

#include "header.h"

ret_table_t search(matrix_t matrix, int i, int j)
{
    //is_highest will determine if position is to be passed
    //from main, it is called with true, and from recursion allways false
    //this makes only the top level responsible for choosing move

    //size for array get smaller each recursion to save space
    //array saves returned values to determine which move to choose
    //depth = 0 at start, 1 for first computer move
    matrix.depth = matrix.depth + 1;
    int fule = how_full(&matrix);
    ret_table_t weights[fule];
    //move determines mini max and what symbol to add to matrix for next level
    char move;
    move = matrix.depth % 2 == 0 ? 'X' : 'O';
    int count = 0;
    for(int i = 0; i < 3; i++)     
    {
        for(int j = 0; j < 3; j++)
        { 
            //if space is full, skip
            if((matrix.matrix[i][j] == 'X') || (matrix.matrix[i][j] == 'O')) continue;
            //if not, set space as move, run recursion, set space back to empty so next move isnt fuckedup (two Xs or Os in one move)
            matrix.matrix[i][j] = move;
            count++;
            weights[count] = search(matrix, i, j);
            matrix.matrix[i][j] = ' ';
        }
    }

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
            ret.idx = i;
            ret.jdx = j;
        }        
    }


    //here will be sorting and returning in the higher layers



    //if im not mistaken, this should not happen, but ill leave it here for the time beeing and delete if everything goes as planned
    if(matrix.depth > 9)
    {
        printf("\ndaco sa pojebalo v rekurzii kamo\n");
        ret_table_t ret;
        ret.depth_reached = matrix.depth;
        ret.weight = 696769;
        ret.idx = i;
        ret.jdx = j;
    
        return ret;
    }

    return ret;
}