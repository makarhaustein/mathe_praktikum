#include "spielablauf.h"
#include "unit.h"
#include "Minmax.h"
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
                int turn = player.start_turn(); 
                while(turn < 0){
                    turn = mapra::NextTurn(turn); 
                    turn = player.next_turn(turn); 
                }
            }
    }
}
