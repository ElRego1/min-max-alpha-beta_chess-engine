#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>

class Game {

 public:
  std::vector<std::vector<char*>> _print_board;
  // std::vector<std::vector<char>> positions;

  char m_color = -1;
  std::vector<std::vector<char>> m_board;
	std::vector<std::vector<char>> m_pieces;

  char e_color = -1;
  std::vector<std::vector<char>> e_board;
	std::vector<std::vector<char>> e_pieces;

  Game(char wb);

  void remake_print_board(char wb);

  // TODO
  void apply_move_m(std::vector<char> &move);
  // TODO
  void undo_move_m(std::vector<char> &move);

  // TODO
  void apply_move_e(std::vector<char> &move);
  // TODO
  void undo_move_e(std::vector<char> &move);

  bool game_over();
  bool is_check_m();
  bool is_check_e();
};
#endif // GAME_H
