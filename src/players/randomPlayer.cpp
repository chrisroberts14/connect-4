// Random player implementation
#include "randomPlayer.h"
#include <random>

void randomPlayer::make_move() {
  // Get the valid moves
  const std::vector<int> valid_moves = game_board.lock()->get_valid_moves();
  // Choose a random move
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(0, static_cast<int>(valid_moves.size()) - 1);
  const int move = valid_moves[dis(gen)];
  // Make the move
  game_board.lock()->make_move(move, player_id);
}
