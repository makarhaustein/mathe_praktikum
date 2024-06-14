// Board.h
#ifndef MinMax_H_
#define MinMax_H_

#include <vector>
#include <iostream>
#include "unit.h"
#include "Board.h"

class Minmax {
public:
     //minmax choose 
     //get int -> update board -> do minmax -> give int 
     //heuristic
     int minmax(int turn); 
     int next_turn(int opposite_turn); 
     int heuristic(); 
     int start_turn(); 

private:
    Board current_board; 
};
#endif  // BOARD_H_