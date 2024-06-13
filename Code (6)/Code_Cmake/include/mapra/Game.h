// Copyright (c) 2022, The MaPra Authors.

#ifndef Game_H_
#define Game_H_
#include <vector>
#include "unit.h"
#include "Board.h"
#include <iostream>
#include <ostream>

  // namespace mapra
  class Game{
    public: 
        Board playing_surface; 
        const int  no_of_games = mapra::kNumGames;  
        std::vector<int> games_won; 
        void clear_board(); 
        void set_stone(int coloumn, int row, int color);
        int game_won(); 
        void print(); 

    private: 
        int helper(int rows, int cols); 
        int helper2(int rows, int cols); 
        int helper3(int rows, int cols); 

  };

#endif  // UNIT_H_
