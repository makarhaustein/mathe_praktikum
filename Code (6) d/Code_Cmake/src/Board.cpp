#include "../include/mapra/Board.h"


Board::Board(){
    std::vector<int> a(mapra::kNumCols,0);
    std::vector<std::vector<int>> b(mapra:: kNumRows ,a);
    this->board = b;
}

Board::Board(int coloumn, int row){
    std::vector<int> a(coloumn,0);
    std::vector<std::vector<int>> b(row,a);
    this->board = b;
}

Board::Board(const Board &b){
    this->board = b.board;
}
bool Board::check_x_y(int row, int cols){
    if(row >= this->board.size() || cols >= this->board[0].size() || row < 0 || cols < 0 ){
        return false; 
    }   
    return true;
}


int Board::get_x_y(int coloumn, int row){
    if(!check_x_y(row,coloumn)){
        std:: cout << "invalid corodinate entered get_x_y, try again"  << std:: endl;
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

void Board::set_x(int cols, int color){
    if (color > 2 || color < 0 || cols < 0 || cols >= this->board[0].size() ){
            std:: cout << "invalid  entered, try again"  << std:: endl;
            return; 
        }
    for (int i = this->board.size()-1; i >= 0; i--){
        if(this->get_x_y(cols,i) == 0){
            this->set_x_y(cols,i,color); 
            return; 
        }
    }
}

void Board::set_x_y(int coloumn, int row, int color){
        if (color > 2 || color < 0){
            std:: cout << "invalid color entered, try again"  << std:: endl;
            return; 
        }
        else if(!check_x_y(row,coloumn)){
        std:: cout << "invalid corodinate entered 0, try again"  << std:: endl;
        return; 
        }
        else if (get_x_y(coloumn,row) != 0){
             std:: cout << "already filled" << coloumn << " " << row  << " tried: " << color << "have: " << get_x_y(coloumn,row)  << std:: endl;
        return; 
        }
         this->board[row][coloumn] = color; 
}
void Board::set_x_y_o(int coloumn, int row){
        if(!check_x_y(row,coloumn)){
        std:: cout << "invalid corodinate entered 0, try again"  << std:: endl;
        return; 
        }
        else if (get_x_y(coloumn,row) == 0){
             std:: cout << "already filled " << coloumn << "  " << row  << " tried: " << 0 << " have: " << get_x_y(coloumn,row)  << std:: endl;
        return; 
        }
         this->board[row][coloumn] = 0; 
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

void Board::clear(){
    for(int i = 0; i < this->board.size(); i++){
        for(int j= 0; j < this->board[0].size(); j++){
            this->board[i][j] = 0; 
        }
    }
}
