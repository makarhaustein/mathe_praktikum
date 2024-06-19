    #include "../include/mapra/Game.h"
    #include "../include/mapra/Minmax.h"
    #include "../include/mapra/unit.h"
    #include "../include/mapra/spielablauf.h"
    #include <iostream>
    #include <assert.h>
    #include <time.h>
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
    void trial_game(){
        mapra::StartGame(4); 
        int j = mapra::NextTurn(0); 
    }
 void testHeuristic() {
    Minmax minmax;
    Board &board = minmax.current_board;

    // Test 1: Horizontal win for yellow
    board.set_x_y(0, 0, 2);
    board.set_x_y(1, 0, 2);
    board.set_x_y(2, 0, 2);
    board.set_x_y(3, 0, 2);
    assert(minmax.heuristic() == 1);
    board.clear();

    // Test 2: Vertical win for red
    board.set_x_y(0, 0, 1);
    board.set_x_y(0, 1, 1);
    board.set_x_y(0, 2, 1);
    board.set_x_y(0, 3, 1);
    assert(minmax.heuristic() == -1);
    board.clear();

    // Test 3: No win but some yellow stones
    board.set_x_y(0, 0, 2);
    board.set_x_y(1, 0, 2);
    board.set_x_y(2, 0, 2);
    std::cout<< minmax.heuristic() << std::endl; 
    board.clear();

    // Test 4: No win but some red stones
    board.set_x_y(0, 0, 1);
    board.set_x_y(1, 0, 1);
    board.set_x_y(2, 0, 1);
    std::cout<< minmax.heuristic() << std::endl; 
    board.clear();
    //Test 5: Diagonals
    board.set_x_y(0, 0, 1);
    board.set_x_y(1, 1, 1);
    board.set_x_y(2, 2, 1);
   std::cout<< minmax.heuristic() << std::endl; 
    board.clear();
    board.set_x_y(1, 0, 1);
    board.set_x_y(2, 1, 1);
    board.set_x_y(3, 2, 1);
    std::cout<< minmax.heuristic() << std::endl; 
    board.clear();
    //test 6: Anti-Diagonals: 
    board.set_x_y(6, 0, 1);
    board.set_x_y(5, 1, 1);
    board.set_x_y(4, 2, 1);
    std::cout<< minmax.heuristic() << std::endl; 
    board.clear();
    //mix 
    board.set_x_y(0, 0, 2);
    board.set_x_y(1, 0, 2);
    board.set_x_y(2, 0, 2);
    board.set_x_y(0, 1, 2);
     board.set_x_y(0, 2, 2);
      board.set_x_y(0, 3, 2);
    std::cout<< minmax.heuristic() << std::endl; 
    board.clear();

    std::cout << "All heuristic tests passed!" << std::endl;
}

 void runBoardTests() {
    // Test 1: Create a board with default constructor and check dimensions
    Board b1;
    assert(b1.get_rows() == mapra::kNumRows);
    assert(b1.get_coloumn() == mapra::kNumCols);
    std::cout << "Test 1 passed: Default constructor initializes board with correct dimensions." << std::endl;

    // Test 2: Create a board with specific dimensions and check
    Board b2(7, 6);
    assert(b2.get_rows() == 6);
    assert(b2.get_coloumn() == 7);
    std::cout << "Test 2 passed: Custom constructor initializes board with given dimensions." << std::endl;

    // Test 3: Check the get_x_y method with valid and invalid coordinates
    b2.set_x_y(3, 2, 1); // Set position (3,2) to red (1)
    assert(b2.get_x_y(3, 2) == 1);
    assert(b2.get_x_y(7, 6) == -1); // Out of bounds
    std::cout << "Test 3 passed: get_x_y method returns correct value and handles invalid coordinates." << std::endl;

    // Test 4: Check the set_x method to insert a stone in the correct position
    b2.set_x(3, 2); // Set column 3 with yellow (2)
    assert(b2.get_x_y(3, 0) == 2); // Yellow stone should be at the bottom
    b2.set_x(3, 1); // Set column 3 with red (1)
    assert(b2.get_x_y(3, 1) == 1); // Red stone should be above the yellow stone
    std::cout << "Test 4 passed: set_x method correctly inserts stones into the board." << std::endl;

    // Test 5: Ensure that setting a stone in a filled column does not change the board
    for (int i = 0; i < b2.get_rows(); ++i) {
        b2.set_x_y(4, i, 2); // Fill column 4 with yellow stones
    }
    b2.set_x(4, 1); // Try to set another red stone in the already filled column
    assert(b2.get_x_y(4, 5) == 2); // The top of column 4 should still be yellow
    std::cout << "Test 5 passed: Cannot insert stone into a fully filled column." << std::endl;

    // Test 6: Check the clear method
    b2.clear();
    for (int i = 0; i < b2.get_rows(); ++i) {
        for (int j = 0; j < b2.get_coloumn(); ++j) {
            assert(b2.get_x_y(j, i) == 0); // All positions should be cleared
        }
    }
    std::cout << "Test 6 passed: clear method resets the board to its initial state." << std::endl;

    // Test 7: Ensure that copy constructor works correctly
    Board b3(b2);
    assert(b3.get_rows() == b2.get_rows());
    assert(b3.get_coloumn() == b2.get_coloumn());
    for (int i = 0; i < b2.get_rows(); ++i) {
        for (int j = 0; j < b2.get_coloumn(); ++j) {
            assert(b3.get_x_y(j, i) == b2.get_x_y(j, i)); // All positions should match
        }
    }
    std::cout << "Test 7 passed: Copy constructor creates a correct copy of the board." << std::endl;

    // Test 8: Ensure that color checking methods work correctly
    b2.set_x_y(0, 0, 1); // Set position (0,0) to red
    b2.set_x_y(1, 0, 2); // Set position (1,0) to yellow
    assert(b2.color_red_xy(0, 0) == true);
    assert(b2.color_yellow_xy(0, 0) == false);
    assert(b2.color_red_xy(1, 0) == false);
    assert(b2.color_yellow_xy(1, 0) == true);
    std::cout << "Test 8 passed: color checking methods correctly identify the stone colors." << std::endl;

    // Test 9: Ensure the print method works (manual verification needed)
    std::cout << "Test 9: Manual verification needed for the print method." << std::endl;
    b2.print();
}
  void testminmax(){
        Minmax minmax;
    // Test 2: Winning Move
        minmax.current_board.clear(); 
        minmax.current_board.set_x_y(3, 5, 2);
        minmax.current_board.set_x_y(3, 4, 2);
        minmax.current_board.set_x_y(3, 3, 2);
        int move = minmax.minmax(0); // AI's turn
        std::cout << "Test 2 - Expected: 3, Got: " << move << std::endl;
    

    // Test 3: Blocking Move
    
         minmax.current_board.clear(); 
         minmax.current_board.set_x_y(3, 5, 1);
         minmax.current_board.set_x_y(3, 4, 1);
         minmax.current_board.set_x_y(3, 3, 1);
         move = minmax.minmax(0); // AI's turn
        std::cout << "Test 3 - Expected: 3, Got: " << move << std::endl;
    

    // Test 4: Mixed Scenario
    
          minmax.current_board.clear(); 
        // Setting up a mixed board state
        minmax.current_board.set_x_y(0, 5, 2);
        minmax.current_board.set_x_y(0, 4, 1);
         minmax.current_board.set_x_y(1, 5, 2);
         minmax.current_board.set_x_y(1, 4, 1);
         minmax.current_board.set_x_y(2, 5, 2);
         minmax.current_board.set_x_y(2, 4, 1);
        minmax.current_board.set_x_y(3, 5, 1);
        minmax.current_board.set_x_y(3, 4, 2);
       
        move = minmax.minmax(0); // AI's turn
        std::cout << "Test 4 - Got: " << move << std::endl;
        minmax.current_board.print(); 
    
  }    
    int main(){
        srand((unsigned) time(NULL)); 
        run_game(); 
        return 0; 
    }
        