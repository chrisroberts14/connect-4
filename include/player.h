#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <string>

#include "board.h"

class player {
// This is an abstract base class for a player in a game
std::string name;
protected:
std::weak_ptr<board> game_board;
public:
  explicit player(std::string name, std::shared_ptr<board> game_board);
  virtual ~player() = default;
  std::string get_name();
  virtual void make_move() = 0;
};



#endif //PLAYER_H
