#include "../include/mapra/Minmax.h"
#include <limits>
//2 -> our 
//1 -> opp 
// Improved heuristic function
double Minmax::heuristic() {
   // Check Columns
    for (int i = 0; i < this->current_board.get_rows() - 3; i++) {
        for (int j = 0; j< this->current_board.get_coloumn(); j++) {
            if (this->current_board.get_x_y(j,i) == 2 && this->current_board.get_x_y(j,i+1) == 2 &&
               this->current_board.get_x_y(j,i+2) == 2 && this->current_board.get_x_y(j,i+3) == 2) {
                return 1;
            } else if (this->current_board.get_x_y(j,i) == 1 && this->current_board.get_x_y(j,i+1) == 1 &&
                      this->current_board.get_x_y(j,i+2) == 1 && this->current_board.get_x_y(j,i+3)== 1) {
                return -1;
            }
        }
    }

    // Check Rws
    for (int i = 0; i < this->current_board.get_rows() ; i++) {
        for (int j = 0; j< this->current_board.get_coloumn()-3; j++) {
            if (this->current_board.get_x_y(j,i) == 2 && this->current_board.get_x_y(j+1,i) == 2 &&
               this->current_board.get_x_y(j+2,i) == 2 && this->current_board.get_x_y(j+3,i) == 2) {
                return 1;
            } else if (this->current_board.get_x_y(j,i) == 1 && this->current_board.get_x_y(j+1,i) == 1 &&
               this->current_board.get_x_y(j+2,i) == 1 && this->current_board.get_x_y(j+3,i) == 1) {
                return -1;
            }
        }
    }
    // Check Diag "/"
    for (int i = 0; i < this->current_board.get_rows() - 3; i++) {
        for (int j = 0; j < this->current_board.get_coloumn() - 3; j++) {
            if (this->current_board.get_x_y(j,i) == 2 && this->current_board.get_x_y(j+1,i+1) == 2 &&
               this->current_board.get_x_y(j+2,i+2) == 2 && this->current_board.get_x_y(j+3,i+3) == 2) {
                return 1;
            } else if (this->current_board.get_x_y(j,i) == 1 && this->current_board.get_x_y(j+1,i+1) == 1 &&
               this->current_board.get_x_y(j+2,i+2) == 1 && this->current_board.get_x_y(j+3,i+3) == 1) {
                return -1;
            }
        }
    }
    // Check Diag "\"
    // Check Diag "/"
    for (int i = 3; i < this->current_board.get_rows() - 3; i++) {
        for (int j = 0; j < this->current_board.get_coloumn() - 3; j++) {
            if (this->current_board.get_x_y(j,i) == 2 && this->current_board.get_x_y(j+1,i-1) == 2 &&
               this->current_board.get_x_y(j+2,i-2) == 2 && this->current_board.get_x_y(j+3,i-3) == 2) {
                return 1;
            } else if (this->current_board.get_x_y(j,i) == 1 && this->current_board.get_x_y(j+1,i-1) == 1 &&
               this->current_board.get_x_y(j+2,i-2) == 1 && this->current_board.get_x_y(j+3,i-3) == 1) {
                return -1;
            }
        }
    }
    double result = 0;
    constexpr double hor_middle_weight = 0.1 / static_cast<int> (mapra::kNumRows);
    constexpr double vert_middle_weight = 0.05 / static_cast<int> (mapra::kNumCols);
    // Prefer Middle
    for (int i = 0; i < this->current_board.get_rows(); i++) {
        for (int j = 0; j <  this->current_board.get_coloumn(); j++) {
            if (this->current_board.get_x_y(j,i) == 2) {
                result += hor_middle_weight *((static_cast<int>(mapra::kNumCols) - 1) * 0.5 - abs((static_cast<int>(mapra::kNumCols) - 1) / 2  - j));
            } else if (this->current_board.get_x_y(j,i) == 1 ) {
                result -= hor_middle_weight *
                          ((static_cast<int>(mapra::kNumCols) - 1) * 0.5 -
                           abs((static_cast<int>(mapra::kNumCols) - 1) / 2 - j));
            }
        }
    }
    // Prefer Bottom
    for (int i = 0; i < this->current_board.get_rows(); i++) {
        for (int j = 0; j < this->current_board.get_coloumn(); j++) {
         if (this->current_board.get_x_y(j,i) == 2) {
                result += vert_middle_weight *
                          ((static_cast<int>(mapra::kNumRows) - 1) * 0.5 -
                           abs((static_cast<int>(mapra::kNumRows) - 1) / 2  - i));
            } else if (this->current_board.get_x_y(j,i) == 1 ) {
                result -= vert_middle_weight *
                          ((static_cast<int>(mapra::kNumRows) - 1) * 0.5 -
                           abs((static_cast<int>(mapra::kNumRows) - 1) / 2 - i));
            }
        }
    }
   
    return result;
}

// Minimax with alpha-beta pruning
std::pair<int, double> Minmax::minmaxAlphaBeta(int turn, int depth) {
    if (depth == 6 ) {
        return {-1, heuristic()};
    }

    if (turn == 0) { // Maximizing player's turn
        double maxEval = -2;
        int bestMove = -1;
        for (int i = 0; i < this->current_board.get_coloumn(); i++) {
            if (this->current_board.get_x_y(i, 0) == 0) { // still empty
                this->current_board.set_x(i, 2); // placing yellow (maximizing)
                double eval = minmaxAlphaBeta(1, depth + 1).second;
                if (eval > maxEval) {
                    maxEval = eval;
                    bestMove = i;
                }else if (eval == maxEval){
                    if( rand() % 2 == 0){
                        bestMove = i; 
                    }
                }
                // Undo move
                for (int j = 0; j < this->current_board.get_rows(); j++) {
                    if (this->current_board.get_x_y(i, j) == 2) {
                        this->current_board.set_x_y_o(i, j);
                        break;
                    }
                }
                 // Beta cutoff
            }
        }
        
        std::pair<int,double>  draw = {-1,0}; 
        std::pair<int,double>  dr = {bestMove, maxEval}; 
        return  (maxEval == -2 ) ?  draw : dr  ; 
    } else { // Minimizing player's turn
        double minEval = 2;
        int bestMove = -1;
        for (int i = 0; i < this->current_board.get_coloumn(); i++) {
            if (this->current_board.get_x_y(i, 0) == 0) { // still empty
                this->current_board.set_x(i, 1); // placing red (minimizing)
                double eval = minmaxAlphaBeta(0, depth + 1).second;
                if (eval < minEval) {
                    minEval = eval;
                    bestMove = i;
                }
               
                // Undo move
                for (int j = 0; j < this->current_board.get_rows(); j++) {
                    if (this->current_board.get_x_y(i, j) == 1) {
                        this->current_board.set_x_y_o(i, j);
                        break;
                    }
                }
                // Alpha cutoff
            }
        }
        std::pair<int,double>  draw = {-1,0}; 
        std::pair<int,double>  dr = {bestMove, minEval}; 
        return  (minEval == 2 ) ?  draw : dr  ; 
    }
}

int Minmax::minmax(int turn) {
    return minmaxAlphaBeta(turn, 0).first;
}

int Minmax::next_turn(int opposite_turn,int first) {
    this->current_board.set_x(opposite_turn, first); //first = 1 -> we started, 2 --> opp started

    return minmax((first == 1) ? 0: 1); // Call our turn
}
