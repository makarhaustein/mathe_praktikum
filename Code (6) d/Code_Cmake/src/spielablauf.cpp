#include "../include/mapra/spielablauf.h"

void run_game(){
    mapra :: StartGame(4); 
    Minmax player; 
    for(int i = 0; i < mapra::kNumGames; i++){
            if( i % 2 == 0){
                    int turn = mapra::NextTurn(-1); 
                    while(turn < 0){
                        turn = player.next_turn(turn); 
                        turn = mapra::NextTurn(turn); 
                    }
            }else{
                int turn = rand() % mapra::kNumCols; 
                while(turn < 0){
                    turn = mapra::NextTurn(turn); 
                    turn = player.next_turn(turn); 
                }
            }
    }
}
