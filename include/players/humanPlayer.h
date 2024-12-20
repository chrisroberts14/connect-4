//
// Created by chris on 20/12/24.
//

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "player.h"

class humanPlayer final : public player {
  static std::string get_move_from_user() ;
public:
    // Constructor
    humanPlayer(const std::string &name, const std::shared_ptr<board> &game_board, cell_state player_id) : player(name, game_board, player_id) {}

    void make_move() override;
};

#endif //HUMANPLAYER_H
