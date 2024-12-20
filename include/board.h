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
  std::vector<std::vector<cell_state>> board_state;
  int rows;
  int cols;
  int win_length;

  [[nodiscard]] bool row_win(cell_state player) const;
  [[nodiscard]] bool col_win(cell_state player) const;
  [[nodiscard]] bool diag_win(cell_state player) const;
public:
  board(int rows, int cols, int win_length);
  std::vector<int> get_valid_moves();
  void make_move(int col, cell_state player);
  [[nodiscard]] bool has_won(cell_state player) const;
  bool is_full() const;
  void print() const;
};

#endif //BOARD_H
