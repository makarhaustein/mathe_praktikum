    #include "Game.h"

    int main(){
        Game game;  // Create a new game

        // Test 1: Fill a row with 4 consecutive red stones
        std::cout << "Test 1: Fill a row with 4 consecutive red stones" << std::endl;
        game.set_stone(0, 0, 1);
        game.set_stone(1, 0, 1);
        game.set_stone(2, 0, 1);
        game.set_stone(3, 0, 1);
        game.playing_surface.print();
        if (game.game_won() == 1) {
            std::cout << "Player 1 wins! (Row test passed)" << std::endl;
        } else {
            std::cout << "Test failed: Player 1 should have won with a row" << std::endl;
        }
        game.clear_board();  // Clear the board

        // Test 2: Fill a column with 4 consecutive red stones
        std::cout << "Test 2: Fill a column with 4 consecutive red stones" << std::endl;
        game.set_stone(0, 0, 1);
        game.set_stone(0, 1, 1);
        game.set_stone(0, 2, 1);
        game.set_stone(0, 3, 1);
        game.playing_surface.print();
        if (game.game_won() == 1) {
            std::cout << "Player 1 wins! (Column test passed)" << std::endl;
        } else {
            std::cout << "Test failed: Player 1 should have won with a column" << std::endl;
        }
        game.clear_board();  // Clear the board

        // Test 3: Fill a main diagonal with 4 consecutive red stones (top-left to bottom-right)
        std::cout << "Test 3: Fill a main diagonal with 4 consecutive red stones (top-left to bottom-right)" << std::endl;
        game.set_stone(0, 0, 1);
        game.set_stone(1, 1, 1);
        game.set_stone(2, 2, 1);
        game.set_stone(3, 3, 1);
        game.playing_surface.print();
        if (game.game_won() == 1) {
            std::cout << "Player 1 wins! (Main diagonal test passed)" << std::endl;
        } else {
            std::cout << "Test failed: Player 1 should have won with a main diagonal" << std::endl;
        }
        game.clear_board();  // Clear the board

        // Test 4: Fill an anti-diagonal with 4 consecutive red stones (top-right to bottom-left)
        std::cout << "Test 4: Fill an anti-diagonal with 4 consecutive red stones (top-right to bottom-left)" << std::endl;
        game.set_stone(3, 0, 1);
        game.set_stone(2, 1, 1);
        game.set_stone(1, 2, 1);
        game.set_stone(0, 3, 1);
        game.playing_surface.print();
        if (game.game_won() == 1) {
            std::cout << "Player 1 wins! (Anti-diagonal test passed)" << std::endl;
        } else {
            std::cout << "Test failed: Player 1 should have won with an anti-diagonal" << std::endl;
        }
        game.clear_board();  // Clear the board

        std::cout << "All tests completed." << std::endl;
        return 0; 
    }
        