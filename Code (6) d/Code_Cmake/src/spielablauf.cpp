#include "../include/mapra/spielablauf.h"
#include <iostream>

void run_game(){
    mapra :: StartGame(4); 
    Minmax player; 
    for(int i = 0; i < mapra::kNumGames; i++){
        std:: cout << i << std::endl;
            if( i % 2 == 1){
                    
                    int turn = mapra::NextTurn(-1); 
                    turn = std::abs(turn); 
                    
                    while(turn >= 0){
                        turn = player.next_turn(turn,2); 
                        if(turn == -1){
                            break; 
                        }
                        turn = mapra::NextTurn(turn); 
                        
                    }
            }else{
                int turn = rand() % mapra::kNumCols; 
                 std:: cout << turn << std::endl;
                while(turn >= 0){
                    turn = player.next_turn(turn,1); 
                     if(turn == -1){
                            break; 
                        }
                    turn = mapra::NextTurn(turn); 
                    
                }
            }
    }
}
