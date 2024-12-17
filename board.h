// Represents the board of the game

#ifndef BOARD_H
#define BOARD_H
#include <vector>

enum class cell_state {
  empty,
  player1,
  player2
};

class board {
  std::vector<std::vector<int>> board_state;
  int rows;
  int cols;
  int win_length;
public:
  board(int rows, int cols, int win_length);
  void make_move(int col, cell_state player);
  bool has_won(cell_state player);
};

#endif //BOARD_H
