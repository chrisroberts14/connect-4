// Game class

#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "board.h"
#include <memory>

class game {
// Each game has 2 players
std::unique_ptr<player> player1;
std::unique_ptr<player> player2;
std::shared_ptr<board> game_board;
public:
  game(std::string player1, std::string player2, int rows, int cols, int win_length);
  void run();
};

#endif //GAME_H
