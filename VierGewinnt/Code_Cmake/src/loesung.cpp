#include "../include/mapra/unit.h"
#include <cmath>
#include <cstdio>
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace mapra;

void ThrowInColumn(vector<vector<int>> *board, bool is_max, int col) {
    for (int row = 0; row < static_cast<int>(kNumRows); row++) {
        if (board->at(row)[col] == 0) {
            if (is_max) {
                board->at(row)[col] = 1;
                return;
            } else {
                board->at(row)[col] = -1;
                return;
            }
        }
    }
}

void TakeOutOfColumn(vector<vector<int>> *board, int col) {
    for (int row = static_cast<int>(kNumRows) - 1; row >= 0; row--) {
        if (board->at(row)[col] != 0) {
            board->at(row)[col] = 0;
            return;
        }
    }
}

float EvaluateBoard(vector<vector<int>> *board) {
    // Check Columns
    for (int i = 0; i < static_cast<int>(kNumRows) - 3; i++) {
        for (int j = 0; j < static_cast<int>(kNumCols); j++) {
            if (board->at(i)[j] == 1 && board->at(i + 1)[j] == 1 &&
                board->at(i + 2)[j] == 1 && board->at(i + 3)[j] == 1) {
                return 1;
            } else if (board->at(i)[j] == -1 && board->at(i + 1)[j] == -1 &&
                       board->at(i + 2)[j] == -1 && board->at(i + 3)[j] == -1) {
                return -1;
            }
        }
    }

    // Check Rws
    for (int i = 0; i < static_cast<int>(kNumRows); i++) {
        for (int j = 0; j < static_cast<int>(kNumCols) - 3; j++) {
            if (board->at(i)[j] == 1 && board->at(i)[j + 1] == 1 &&
                board->at(i)[j + 2] == 1 && board->at(i)[j + 3] == 1) {
                return 1;
            } else if (board->at(i)[j] == -1 && board->at(i)[j + 1] == -1 &&
                       board->at(i)[j + 2] == -1 && board->at(i)[j + 3] == -1) {
                return -1;
            }
        }
    }
    // Check Diag "/"
    for (int i = 0; i < static_cast<int>(kNumRows) - 3; i++) {
        for (int j = 0; j < static_cast<int>(kNumCols) - 3; j++) {
            if (board->at(i)[j] == 1 && board->at(i + 1)[j + 1] == 1 &&
                board->at(i + 2)[j + 2] == 1 && board->at(i + 3)[j + 3] == 1) {
                return 1;
            } else if (board->at(i)[j] == -1 && board->at(i + 1)[j + 1] == -1 &&
                       board->at(i + 2)[j + 2] == -1 &&
                       board->at(i + 3)[j + 3] == -1) {
                return -1;
            }
        }
    }
    // Check Diag "\"
    for (int i = 3; i < static_cast<int>(kNumRows); i++) {
        for (int j = 0; j < static_cast<int>(kNumCols) - 3; j++) {
            if (board->at(i)[j] == 1 && board->at(i - 1)[j + 1] == 1 &&
                board->at(i - 2)[j + 2] == 1 && board->at(i - 3)[j + 3] == 1) {
                return 1;
            } else if (board->at(i)[j] == -1 && board->at(i - 1)[j + 1] == -1 &&
                       board->at(i - 2)[j + 2] == -1 &&
                       board->at(i - 3)[j + 3] == -1) {
                return -1;
            }
        }
    }
    float result = 0;
    constexpr float hor_middle_weight = 0.1f / (static_cast<int>(kNumCols) - 1);
    constexpr float vert_middle_weight = 0.05f / (static_cast<int>(kNumRows) - 1);
    // Prefer Middle
    for (int i = 0; i < static_cast<int>(kNumRows); i++) {
        for (int j = 0; j < static_cast<int>(kNumCols); j++) {
            if (board->at(i)[j] == 1) {
                result += hor_middle_weight *
                          ((static_cast<int>(kNumCols) - 1) * 0.5f -
                           abs((static_cast<int>(kNumCols) - 1) / 2  - j));
            } else if (board->at(i)[j] == -1) {
                result -= hor_middle_weight *
                          ((static_cast<int>(kNumCols) - 1) * 0.5f -
                           abs((static_cast<int>(kNumCols) - 1) / 2 - j));
            }
        }
    }
    // Prefer Bottom
    for (int i = 0; i < static_cast<int>(kNumRows); i++) {
        for (int j = 0; j < static_cast<int>(kNumCols); j++) {
            if (board->at(i)[j] == 1) {
                result += vert_middle_weight *
                          ((static_cast<int>(kNumRows) - 1) * 0.5f -
                           abs((static_cast<int>(kNumRows) - 1) / 2  - i));
            } else if (board->at(i)[j] == -1) {
                result -= vert_middle_weight *
                          ((static_cast<int>(kNumRows) - 1) * 0.5f -
                           abs((static_cast<int>(kNumRows) - 1) / 2 - i));
            }
        }
    }
   return result;
}

int GetMaxRandomIndex(vector<float> *vec) {
    float max_val = -2;
    int max_val_count = 0;
    for (int i = 0; i < static_cast<int>(kNumCols); i++) {
        if (vec->at(i) > max_val) {
            max_val = vec->at(i);
            max_val_count = 1;
        } else if (vec->at(i) == max_val) {
            max_val_count++;
        }
    }

    int take_occurence = rand() % max_val_count;
    for (int i = 0; i < static_cast<int>(kNumCols); i++) {
        if (vec->at(i) == max_val) {
            if (take_occurence == 0) {
                return i;
            }
            take_occurence -= 1;
        }
    }
    return -2;
}

int GetMinRandomIndex(vector<float> *vec) {
    float min_val = 2;
    int min_val_count = 0;
    for (int i = 0; i < static_cast<int>(kNumCols); i++) {
        if (vec->at(i) < min_val) {
            min_val = vec->at(i);
            min_val_count = 1;
        } else if (vec->at(i) == min_val) {
            min_val_count++;
        }
    }
    int take_occurence = rand() % min_val_count;
    for (int i = 0; i < static_cast<int>(kNumCols); i++) {
        if (vec->at(i) == min_val) {
            if (take_occurence == 0) {
                return i;
            }
            take_occurence -= 1;
        }
    }
    return -2;
}

float MinPlayer(vector<vector<int>> *board, int look_ahead);

float MaxPlayer(vector<vector<int>> *board, int look_ahead) {
    float eval = EvaluateBoard(board);
    if (eval == 1 || eval == -1 || look_ahead == 0) {
        return eval;
    }
    float max_val = -2;
    float val;
    for (int col = 0; col < static_cast<int>(kNumCols); col++) {
        if (board->at(static_cast<int>(kNumRows) - 1)[col] == 0) {
            ThrowInColumn(board, true, col);
            val = MinPlayer(board, look_ahead - 1);
            if (val > max_val) {
                max_val = val;
            }
            TakeOutOfColumn(board, col);
        }
    }
    return max_val == -2 ? 0 : max_val; // if max_val at default val then all
                                        // cols are full and draw is forced
}

float MinPlayer(vector<vector<int>> *board, int look_ahead) {
    float eval = EvaluateBoard(board);
    if (eval == 1 || eval == -1 || look_ahead == 0) {
        return eval;
    }
    float min_val = 2;
    float val;
    for (int col = 0; col < static_cast<int>(kNumCols); col++) {
        if (board->at(static_cast<int>(kNumRows) - 1)[col] == 0) {
            ThrowInColumn(board, false, col);
            val = MaxPlayer(board, look_ahead - 1);
            if (val < min_val) {
                min_val = val;
            }
            TakeOutOfColumn(board, col);
        }
    }
    return min_val == 2 ? 0 : min_val; // if min_val at default val then all
                                       // cols are full and draw is forced
}

int MaxPlayerTop(vector<vector<int>> *board, int look_ahead) {
    vector<float> col_options(kNumCols, -2);
    for (int col = 0; col < static_cast<int>(kNumCols); col++) {
        if (board->at(static_cast<int>(kNumRows) - 1)[col] == 0) {
            ThrowInColumn(board, true, col);
            col_options[col] = MinPlayer(board, look_ahead - 1);
            TakeOutOfColumn(board, col);
        }
    }
    return GetMaxRandomIndex(&col_options);
}

int MinPlayerTop(vector<vector<int>> *board, int look_ahead) {
    vector<float> col_options(kNumCols, 2);
    for (int col = 0; col < static_cast<int>(kNumCols); col++) {
        if (board->at(static_cast<int>(kNumRows) - 1)[col] == 0) {
            ThrowInColumn(board, false, col);
            col_options[col] = MaxPlayer(board, look_ahead - 1);
            TakeOutOfColumn(board, col);
        }
    }
    return GetMinRandomIndex(&col_options);
}
int main() {
    constexpr unsigned int difficulty = 4;
    constexpr int look_ahead = 6;
    StartGame(difficulty);
    srand(time(NULL));
    vector<vector<int>> board(static_cast<int>(kNumRows),
                              vector<int>(static_cast<int>(kNumCols), 0));
    bool firstPlayer;
    for (unsigned int round = 1; round <= kNumGames; round++) {
        for (int row = 0; row < static_cast<int>(kNumRows); row++) {
            for (int col = 0; col < static_cast<int>(kNumCols); col++) {
                board[row][col] = 0;
            }
        }
        if (round % 2 == 0) { // Opp goes first
            ThrowInColumn(&board, true, NextTurn(-1));
            firstPlayer = false;
        } else {
            firstPlayer = true;
        }

        int opponent_turn = 0;
        int my_turn = 0;
        while (true) {
            if (firstPlayer) {
                my_turn = MaxPlayerTop(&board, look_ahead);
            } else {
                my_turn = MinPlayerTop(&board, look_ahead);
            }
            ThrowInColumn(&board, firstPlayer, my_turn);
            opponent_turn = NextTurn(my_turn);
            if (opponent_turn < 0) {
                break;
            } else {
                ThrowInColumn(&board, !firstPlayer, opponent_turn);
            }
        }
    }
}
