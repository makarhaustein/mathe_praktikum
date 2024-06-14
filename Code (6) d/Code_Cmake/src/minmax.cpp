#include "../include/mapra/Minmax.h"

int Minmax::minmax(int turn) {
    const int MAX_DEPTH = 4; // Example depth limit
    return minimaxAlphaBeta(turn, MAX_DEPTH, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
}

int Minmax::minimaxAlphaBeta(int turn, int depth, int alpha, int beta) {
    // Base case: evaluate heuristic if depth limit reached or game over
    if (depth == 0 /* || game over condition */) {
        return heuristic();
    }

    // Maximizing player's turn (assumed to be maximizing for simplicity)
    if (turn == 0) {
        int maxEval = std::numeric_limits<int>::min();
        // Generate possible moves and evaluate recursively
        for (/* each possible move */) {
            // Make move

            // Recursively evaluate
            int eval = minimaxAlphaBeta(next_turn(turn), depth - 1, alpha, beta);

            // Undo move (if necessary for further exploration)
            
            maxEval = std::max(maxEval, eval);
            alpha = std::max(alpha, eval);
            if (beta <= alpha) {
                break; // Beta cutoff
            }
        }
        return maxEval;
    }
    // Minimizing player's turn (assumed to be minimizing for simplicity)
    else {
        int minEval = std::numeric_limits<int>::max();
        // Generate possible moves and evaluate recursively
        for (/* each possible move */) {
            // Make move

            // Recursively evaluate
            int eval = minimaxAlphaBeta(next_turn(turn), depth - 1, alpha, beta);

            // Undo move (if necessary for further exploration)
            
            minEval = std::min(minEval, eval);
            beta = std::min(beta, eval);
            if (beta <= alpha) {
                break; // Alpha cutoff
            }
        }
        return minEval;
    }
}


int Minmax::next_turn(int opposite_turn) {
    this->current_board.set_x(opposite_turn, 2);
    return minmax(0);
}

double Minmax::heuristic() {
    const double z2 = 0.5;  // Define the points for 2 stones
    const double z3 = 0.7;  // Define the points for 3 stones
    int score = 0;

    // Lambda function to evaluate a segment of 4 positions
    auto evaluateSegment = [&](int yellowCount, int redCount) -> int {
        if (yellowCount == 4) return 1;  // Four yellow stones
        if (redCount == 4) return -1;    // Four red stones
        if (yellowCount > 0 && redCount > 0) return 0;  // Mixed stones
        if (yellowCount == 3) return z3;
        if (yellowCount == 2) return z2;
        if (redCount == 3) return -z3;
        if (redCount == 2) return -z2;
        return 0;
    };

    // Check all horizontal segments
    for (int row = 0; row < this->current_board.get_rows(); row++) {
        for (int col = 0; col <= this->current_board.get_coloumn() - 4; col++) {
            int yellowCount = 0;
            int redCount = 0;
            for (int i = 0; i < 4; i++) {
                int cellValue = this->current_board.get_x_y(col + i, row);
                if (cellValue == 2) yellowCount++;
                if (cellValue == 1) redCount++;
            }
            int segmentScore = evaluateSegment(yellowCount, redCount);
            if (segmentScore == 1 || segmentScore == -1) return segmentScore;
            score += segmentScore;
        }
    }

    // Check all vertical segments
    for (int col = 0; col < this->current_board.get_coloumn(); col++) {
        for (int row = 0; row <= this->current_board.get_rows() - 4; row++) {
            int yellowCount = 0;
            int redCount = 0;
            for (int i = 0; i < 4; i++) {
                int cellValue = this->current_board.get_x_y(col, row + i);
                if (cellValue == 2) yellowCount++;
                if (cellValue == 1) redCount++;
            }
            int segmentScore = evaluateSegment(yellowCount, redCount);
            if (segmentScore == 1 || segmentScore == -1) return segmentScore;
            score += segmentScore;
        }
    }

    // Check all positive diagonal segments
    for (int row = 0; row <= this->current_board.get_rows() - 4; row++) {
        for (int col = 0; col <= this->current_board.get_coloumn() - 4; col++) {
            int yellowCount = 0;
            int redCount = 0;
            for (int i = 0; i < 4; i++) {
                int cellValue = this->current_board.get_x_y(col + i, row + i);
                if (cellValue == 2) yellowCount++;
                if (cellValue == 1) redCount++;
            }
            int segmentScore = evaluateSegment(yellowCount, redCount);
            if (segmentScore == 1 || segmentScore == -1) return segmentScore;
            score += segmentScore;
        }
    }

    // Check all negative diagonal segments
    for (int row = 3; row < this->current_board.get_rows(); row++) {
        for (int col = 0; col <= this->current_board.get_coloumn() - 4; col++) {
            int yellowCount = 0;
            int redCount = 0;
            for (int i = 0; i < 4; i++) {
                int cellValue = this->current_board.get_x_y(col + i, row - i);
                if (cellValue == 2) yellowCount++;
                if (cellValue == 1) redCount++;
            }
            int segmentScore = evaluateSegment(yellowCount, redCount);
            if (segmentScore == 1 || segmentScore == -1) return segmentScore;
            score += segmentScore;
        }
    }

    return score;
}


