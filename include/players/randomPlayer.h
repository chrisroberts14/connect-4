#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "player.h"

class randomPlayer final : player {
public:
    // Constructor
    randomPlayer(const std::string &name, const std::shared_ptr<board> &game_board) : player(name, game_board) {}

    void make_move() override;
};



#endif //RANDOMPLAYER_H
