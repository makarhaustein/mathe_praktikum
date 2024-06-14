    #include "Game.h"
    #include "unit.h"
    using namespace mapra; 
    void test_game(){
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
    }
    void testBoard() {
    // 1. Test board generation with given specifications
    int cols = 5;
    int rows = 4;
    Board board(cols, rows);
    
    if (board.get_coloumn() != cols || board.get_rows() != rows) {
        std::cout << "Test failed: Board dimensions are incorrect." << std::endl;
        return;
    } else {
        std::cout << "Test passed: Board dimensions are correct." << std::endl;
    }

    // 2. Test inserting correctly using set_x
    board.set_x(2, 1); // insert '1' in column 2 (should go to the bottom most available row)
    
    if (board.get_x_y(2, rows - 1) != 1) { // the bottom-most row should be filled with '1'
        std::cout << "Test failed: set_x did not insert correctly." << std::endl;
        return;
    } else {
        std::cout << "Test passed: set_x inserted correctly." << std::endl;
    }

    // Check if trying to insert in the same column places the value in the next available row
    board.set_x(2, 2); // insert '2' in column 2 (should go to the row above the previously filled position)
    
    if (board.get_x_y(2, rows - 2) != 2) { // the next available row above should be filled with '2'
        std::cout << "Test failed: set_x did not place in the correct position when column partially filled." << std::endl;
        return;
    } else {
        std::cout << "Test passed: set_x placed correctly when column partially filled." << std::endl;
    }

    std::cout << "All tests passed." << std::endl;
}
    int main(){
        testBoard(); 
        return 0; 
    }
        