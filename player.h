//
// Created by chris on 17/12/24.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class player {
// This is an abstract base class for a player in a game
std::string name;
public:
  // Constructor
  explicit player(std::string name);
  // Destructor
  virtual ~player();
  // Get the player's name
  std::string get_name();
  // Make a move in the game
  virtual void make_move() = 0;
};



#endif //PLAYER_H
