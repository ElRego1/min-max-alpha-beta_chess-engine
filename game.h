#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"
#include "constants.h"

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

  std::vector<char> find_next_move();

  // return value: {piece_taken} | info to undo the move
  std::vector<char> apply_move_m(std::vector<char> &move);
  // TODO
  // parameters: {piece_taken}, {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  void undo_move_m(std::vector<char> &info, std::vector<char> &move);

  // return value: {piece_taken} | info to undo the move
  std::vector<char> apply_move_e(std::vector<char> &move);
  // TODO
  // parameters: {piece_taken}, {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  void undo_move_e(std::vector<char> &info, std::vector<char> &move);

  bool is_check_m();
  bool is_check_e();
};

// MODIFIES the internal state of the game !!!
// I didn't want to use "m_board", "m_pieces", "e_board", "e_pieces" as names for the parameters of the function
// to not be missleading and be confused with the Game class's argument. Also because the view of the boards is relative
// the parameters of the funciton are as fallows:
// structure of move: {src_x, src_y, dst_x, dst_y, piece_type, priority_code} | only the first 4 fields in the vector are mandatory
// p_board - personal chess board 
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
// return value: {piece_taken} | we use a vector for return if we want to expand later
// --> piece_taken - the codification is for an enemy piece (11 - 17 with 0 for no piece taken) as the piece is relative to the attacker
std::vector<char> apply_move(std::vector<char> &move, std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

// MODIFIES the internal state of the game !!!
// structure of info: {piece_taken}
// --> piece_taken - the codification is for an enemy piece (11 - 17 with 0 for no piece taken) as the piece is relative to the attacker
// structure of move: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
// --> src_x, src_y, dst_x, dst_y - src and dst are as we are making the move so we want to move from dst to the src position the piece
// p_board - personal chess board 
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
void undo_move(std::vector<char> &info, std::vector<char> &move,
std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

// checks if the king is safe or not
int check_check(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_check_validity(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_knight(char i, char j, std::vector<std::vector<char>> &chess_board);

// possible ways of what a piece can attack
// return a vector of {x, y, piece type}
std::vector<std::vector<char>> check_attack(char i, char j, std::vector<std::vector<char>> &chess_board);
std::vector<char> attacks(char i, char j, std::vector<std::vector<char>> &chess_board);

// all pieces that can attack my piece
// return a vector of {x, y, piece type}
std::vector<std::vector<char>> check_attackers(char i, char j, std::vector<std::vector<char>> &chess_board);
#endif // GAME_H
