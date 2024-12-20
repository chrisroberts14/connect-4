#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include "player.h"

class randomPlayer final : public player {
public:
    // Constructor
    randomPlayer(const std::string &name, const std::shared_ptr<board> &game_board, cell_state player_id) : player(name, game_board, player_id) {}

    void make_move() override;
};



#endif //RANDOMPLAYER_H
