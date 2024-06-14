// Board.h
#ifndef MinMax_H_
#define MinMax_H_

#include <vector>
#include <iostream>
#include "unit.h"
#include "Board.h"
#include <random>
class Minmax {
public:
     //minmax choose 
     //get int -> update board -> do minmax -> give int 
     //heuristic
     Board current_board; 
     int minmax(int turn); 
     int next_turn(int opposite_turn); 
     double heuristic(); 
     int start_turn(); 
     int minimaxAlphaBeta(int turn, int depth, int alpha, int beta);

private:
    
};
#endif  // BOARD_H_