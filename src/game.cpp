//
// Created by chris on 17/12/24.
//

#include "game.h"

#include <iostream>
#include <randomPlayer.h>

game::game(int rows, int cols, int win_length) {
    // Create the game board
    game_board = std::make_shared<board>(rows, cols, win_length);
    // Create the players
    player1 = std::make_unique<randomPlayer>("Player 1", game_board, cell_state::player1);
    player2 = std::make_unique<randomPlayer>("Player 2", game_board, cell_state::player2);
}

void game::run() const {
    // Run each player's turn until the game is over
    while (true) {
        // Player 1's turn
        player1->make_move();
        if (game_board->has_won(cell_state::player1)) {
            std::cout << "Player 1 wins!" << std::endl;
            break;
        }
        if (game_board->is_full()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }
        // Player 2's turn
        player2->make_move();
        if (game_board->has_won(cell_state::player2)) {
            std::cout << "Player 2 wins!" << std::endl;
            break;
        }
        if (game_board->is_full()) {
            std::cout << "It's a draw!" << std::endl;
            break;
        }
    }
    game_board->print();
}



