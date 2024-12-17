// Entry into the game

#include "game.h"
int main(){
  // Create the game and run it with the default settings
  game g(std::make_unique<player>("Player 1"), std::make_unique<player>("Player 2"));
  g.run();
  return 0;
}
