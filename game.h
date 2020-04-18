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
  // returns info to undo the move
  // return value: {src_x, src_y, dst_x, dst_y, piece_taken}
  std::vector<char> apply_move_m(std::vector<char> &move);
  // TODO
  void undo_move_m(std::vector<char> &info, std::vector<char> &move);

  // TODO
  // returns info to undo the move
  // return value: {src_x, src_y, dst_x, dst_y, piece_taken}
  std::vector<char> apply_move_e(std::vector<char> &move);
  // TODO
  void undo_move_e(std::vector<char> &info, std::vector<char> &move);

  bool game_over();
  bool is_check_m();
  bool is_check_e();
};
// I didn't want to use "m_board", "m_pieces", "e_board", "e_pieces" as names for the parameters of the function
// to not be missleading and be confused with the Game class's argument. Also because the view of the boards is relative
// the parameters of the funciton are as fallows:
// p_board - personal chess board 
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
// return value: {src_x, src_y, dst_x, dst_y, piece_taken}
// --> piece_taken - the codification is for an enemy piece (11 - 17 with 0 for no piece taken) as the piece is relative to the attacker
std::vector<char> apply_move(std::vector<std::vector<char>> &p_board, std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

int check_check(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_check_validity(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_knight(char i, char j, std::vector<std::vector<char>> &chess_board);
#endif // GAME_H
