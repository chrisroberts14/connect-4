// Human player implementation

#include "humanPlayer.h"
#include <iostream>

void humanPlayer::make_move() {
  // Print the board
    game_board.lock()->print();
    const std::string move = get_move_from_user();
    game_board.lock()->make_move(std::stoi(move), player_id);
}

std::string humanPlayer::get_move_from_user() {
    std::string move;
    std::cout << "\n" << "Enter your move: ";
    std::cin >> move;
    return move;
}
