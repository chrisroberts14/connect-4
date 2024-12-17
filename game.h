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
std::unique_ptr<board> game_board;
public:
  // Constructor
  game(std::unique_ptr<player> player1, std::unique_ptr<player> player2);
  // Destructor
  ~game();
  // Run the game
  void run();
};

#endif //GAME_H
