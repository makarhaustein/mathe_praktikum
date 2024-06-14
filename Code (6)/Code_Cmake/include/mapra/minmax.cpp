#include "Minmax.h"

int Minmax::minmax(int turn)
{
    return 0;
}

int Minmax::next_turn(int opposite_turn){
    this->current_board.set_x(opposite_turn); 
    return minmax(0);
}

int Minmax::heuristic()
{
    return 0;
}
