// Board.h
#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include <iostream>
#include "unit.h"
class Board {
public:
    Board();
    Board(int coloumn, int row);
    Board(const Board &b);
    bool check_x_y(int x, int y);
    int get_x_y(int coloumn, int row);
    int get_rows();
    int get_coloumn();
    void set_x(int x, int color); 
    bool color_red_xy(int coloum, int row);
    bool color_yellow_xy(int coloum, int row);
    void print();
    void clear(); 
    

private:
    std::vector<std::vector<int>> board;
    void set_x_y(int coloumn, int row, int color);
};

#endif  // BOARD_H_