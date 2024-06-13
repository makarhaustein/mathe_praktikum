#include "Board.h"
#include <iostream>
Board::Board(){
    std::vector<int> a(mapra::kNumRows,0);
    std::vector<std::vector<int>> b(mapra:: kNumCols,a);
    this->board = b;
}

Board::Board(int coloumn, int row){
    std::vector<int> a(row,0);
    std::vector<std::vector<int>> b(coloumn,a);
    this->board = b;
}

Board::Board(const Board &b){
    this->board = b.board;
}
bool Board::check_x_y(int x, int y){
    if(y >= this->board.size() || x >= this->board[0].size() ){
        return false; 
    }   
    return true;
}


int Board::get_x_y(int coloumn, int row){
    if(!check_x_y(coloumn,row)){
        std:: cout << "invalid corodinate entered, try again"  << std:: endl;
        return -1; 
    }
    return this->board[row][coloumn];
}

int Board::get_rows(){
    return this->board.size(); 
}

int Board::get_coloumn(){
     return this->board[0].size(); 
}

void Board::set_x_y(int coloumn, int row, int color){
        if (color > 2 || color < 0){
            std:: cout << "invalid color entered, try again"  << std:: endl;
            return; 
        }
        else if(!check_x_y(coloumn,row)){
        std:: cout << "invalid corodinate entered 0, try again"  << std:: endl;
        return; 
        }
        this->board[row][coloumn] = color; 
}
//returns true if red 
bool Board::color_red_xy(int coloum, int row){
    if(!check_x_y(coloum,row)){
        std:: cout << "invalid corodinate entered, try again"  << std:: endl;
        return false; 
    }
    return get_x_y(coloum,row) == 1;
}
bool Board::color_yellow_xy(int coloum, int row){
    if(!check_x_y(coloum,row)){
        std:: cout << "invalid corodinate entered, try again"  << std:: endl;
        return false; 
    }
    return get_x_y(coloum,row) == 2;
}

void Board::print(){
    std:: cout << "------------------------------------------" << std::endl; 
    std :: cout << "Board printed" << std::endl; 
    for ( std::vector<int> i : this->board){
        for ( int j = 0; j < i.size(); j++ ){
            std::cout << i[j] << "|"; }
        std:: cout << std::endl; 
        for(int j = 0; j < i.size()*2; j++){
             std:: cout << "-"; 
        }
         std:: cout << std::endl; 
    }
    std:: cout << "------------------------------------------" << std::endl; 
    std :: cout << "Board printed ended" << std::endl; 
}

