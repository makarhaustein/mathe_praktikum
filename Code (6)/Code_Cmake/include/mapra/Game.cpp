// Game.cpp
#include "Game.h"


// Method to clear the board
void Game::clear_board() {
    int rows = playing_surface.get_rows();  
    int cols = playing_surface.get_coloumn();  
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            playing_surface.set_x_y(j, i, 0);
        }
    }
}

// Method to set a stone on the board
void Game::set_stone(int coloumn, int row, int color) {
    playing_surface.set_x_y(coloumn, row, color);
}
int Game::helper(int rows, int cols){
    for(int i = 0; i < rows; i++){
        int counter = 0; 
        int previous = -1; 
        for (int j = 0; j < cols; j++){
            if(counter == 4){
                break; }
            if(this->playing_surface.color_red_xy(j,i)) {
                if(previous == 1 || previous == -1){
                    counter ++; 
                }else{   counter = 1; }
                previous = 1;     
            }
            else if(this->playing_surface.color_yellow_xy(j,i)) {
                 if(previous == 2 || previous == -1){
                    counter ++; 
                }else{   counter = 1; }
                previous = 2; 
            }
        }
        if((previous != -1 ) && (counter == 4)){
            return previous; 
        }
    }
    return 0; 
}
int Game::helper2(int rows, int cols){
     //check coloums: 
    for(int i = 0; i < cols; i++){
        int counter = 0; 
        int previous = -1; 
        for (int j = 0; j < rows; j++){
            if(counter == 4){
                break; }
            if(this->playing_surface.color_red_xy(i,j)) {
                if(previous == 1 || previous == -1){
                    counter ++; 
                }else{   counter = 1; }
                previous = 1;     
            }
            else if(this->playing_surface.color_yellow_xy(i,j)) {
                 if(previous == 2 || previous == -1){
                    counter ++; 
                }else{   counter = 1; }
                previous = 2; 
            }
        }
        if((previous != -1 ) && (counter == 4)){
            return previous; 
        }
    }
    return 0;
}
int Game::helper3(int rows, int cols) {
    // Check main diagonals (top-left to bottom-right)
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 0; j <= cols - 4; ++j) {
            int color = playing_surface.get_x_y(j, i);
            if (color != 0 &&
                color == playing_surface.get_x_y(j + 1, i + 1) &&
                color == playing_surface.get_x_y(j + 2, i + 2) &&
                color == playing_surface.get_x_y(j + 3, i + 3)) {
                return color;
            }
        }
    }

    // Check main diagonals starting from first row but different columns
    for (int j = 1; j <= cols - 4; ++j) {
        for (int i = 0; i <= rows - 4; ++i) {
            int color = playing_surface.get_x_y(j + i, i);
            if (color != 0 &&
                color == playing_surface.get_x_y(j + i + 1, i + 1) &&
                color == playing_surface.get_x_y(j + i + 2, i + 2) &&
                color == playing_surface.get_x_y(j + i + 3, i + 3)) {
                return color;
            }
        }
    }

    // Check anti-diagonals (top-right to bottom-left)
    for (int i = 0; i <= rows - 4; ++i) {
        for (int j = 3; j < cols; ++j) {
            int color = playing_surface.get_x_y(j, i);
            if (color != 0 &&
                color == playing_surface.get_x_y(j - 1, i + 1) &&
                color == playing_surface.get_x_y(j - 2, i + 2) &&
                color == playing_surface.get_x_y(j - 3, i + 3)) {
                return color;
            }
        }
    }

    // Check anti-diagonals starting from first column but different rows
    for (int i = 1; i <= rows - 4; ++i) {
        for (int j = cols - 1; j >= 3; --j) {
            int color = playing_surface.get_x_y(j, i + (cols - 1 - j));
            if (color != 0 &&
                color == playing_surface.get_x_y(j - 1, i + (cols - 1 - j) + 1) &&
                color == playing_surface.get_x_y(j - 2, i + (cols - 1 - j) + 2) &&
                color == playing_surface.get_x_y(j - 3, i + (cols - 1 - j) + 3)) {
                return color;
            }
        }
    }

    return 0;
}

// Method to check if a game is won

int Game::game_won() {

    int rows = playing_surface.get_rows();  // Assuming getRows() is implemented in Board class
    int cols = playing_surface.get_coloumn();  // Assuming getCols() is implemented in Board class

    //check rows: 
    int winner = helper(rows,cols); 
    if(winner != 0){
        return winner; 
    }
    winner = helper2(rows,cols); 
    if(winner != 0){
        return winner; 
    }
     winner = helper3(rows,cols); 
    if(winner != 0){
        return winner; 
    }
    return 0; 
    
}

void Game::print(){
    this->playing_surface.print(); 
}
