//
// Created by chris on 17/12/24.
//

#include "board.h"

#include <algorithm>
#include <functional>
#include <fmt/core.h>
#include <fmt/color.h>

board::board(const int rows, const int cols, const int win_length) : rows(rows), cols(cols), win_length(win_length) {
  // Initialize the board to be empty
  board_state = std::vector(rows, std::vector(cols, cell_state::empty));
}

std::vector<int> board::get_valid_moves() {
  // If there are any empty cells in a column it must be a valid move
  // Go through each row
  std::vector<int> valid_moves;
  for (int col = 0; col < cols; col++) {
    if (std::ranges::any_of(board_state, [col](const std::vector<cell_state> &row) { return row[col] == cell_state::empty; })) {
      valid_moves.push_back(col);
    }
  }
  return valid_moves;
}

void board::make_move(const int col, const cell_state player) {
  // Find the first empty cell in the column and place the player's piece there
  for (int row = 0; row < rows; row++) {
    if (board_state[row][col] == cell_state::empty) {
      board_state[row][col] = player;
      return;
    }
  }
}

bool board::row_win(const cell_state player) const {
  // Check for a win in each row
  for (int row = 0; row < rows; row++) {
    for (int col = 0; col < cols - win_length + 1; col++) {
      bool win = true;
      for (int i = 0; i < win_length; i++) {
        if (board_state[row][col + i] != player) {
          win = false;
          break;
        }
      }
      if (win) {
        return true;
      }
    }
  }
  return false;
}

bool board::col_win(cell_state player) const {
  // Check for a win in each column
  for (int col = 0; col < cols; col++) {
    for (int row = 0; row < rows - win_length + 1; row++) {
      bool win = true;
      for (int i = 0; i < win_length; i++) {
        if (board_state[row + i][col] != player) {
          win = false;
          break;
        }
      }
      if (win) {
        return true;
      }
    }
  }
  return false;
}

bool board::diag_win(cell_state player) const {
  // Check for a win in each diagonal
  // Check the diagonals from the top left
  for (int row = 0; row < rows - win_length + 1; row++) {
    for (int col = 0; col < cols - win_length + 1; col++) {
      bool win = true;
      for (int i = 0; i < win_length; i++) {
        if (board_state[row + i][col + i] != player) {
          win = false;
          break;
        }
      }
      if (win) {
        return true;
      }
    }
  }
  // Check the diagonals from the top right
  for (int row = 0; row < rows - win_length + 1; row++) {
    for (int col = win_length - 1; col < cols; col++) {
      bool win = true;
      for (int i = 0; i < win_length; i++) {
        if (board_state[row + i][col - i] != player) {
          win = false;
          break;
        }
      }
      if (win) {
        return true;
      }
    }
  }
  return false;
}


bool board::has_won(const cell_state player) const {
  // Check for a win
  if (row_win(player) || col_win(player) || diag_win(player)) {
    return true;
  }
  return false;
}

bool board::is_full() const {
  // Check if the board is full
  return std::ranges::all_of(board_state, [](const std::vector<cell_state> &row) {
    return std::ranges::all_of(row, [](const cell_state cell) { return cell != cell_state::empty; });
  });
}

void board::print() const {
  // Print the board with red and blue pieces
  for (int row = rows - 1; row >= 0; row--) {
    fmt::print("|");
    for (int col = 0; col < cols; col++) {
      if (board_state[row][col] == cell_state::player1) {
        fmt::print(fmt::fg(fmt::color::red) | fmt::emphasis::bold, " O ");
      } else if (board_state[row][col] == cell_state::player2) {
        fmt::print(fmt::fg(fmt::color::blue) | fmt::emphasis::bold, " O ");
      } else {
        fmt::print("   ");
      }
      fmt::print("|");
    }
    fmt::print("\n");
  }
}



