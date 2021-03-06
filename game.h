#ifndef GAME_H
#define GAME_H

#include <bits/stdc++.h>
#include "minimax.h"
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

void print();

  void remake_print_board(char wb);

  // to be called in order to start the minimax
  // return value: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  // --> return value is an empty vector if no move that doesn't lead to checkmate is found
  // --> In short we lose inevitably if 2 gods play so we have to give comand that we surender
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
// return value: {piece_taken_my_codification, piece_taken_enemy_codification, promotion?} | we use a vector for return if we want to expand later
// --> piece_taken_my_codification - the codification is for an enemy piece (11 - 17 with 0 for no piece taken) as the piece is relative to the attacker
// --> promotion? - if there was a promotion of a pawn | info to undo the move later
inline std::vector<char> apply_move(std::vector<char> &move, std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

// MODIFIES the internal state of the game !!!
// structure of info: {piece_taken_my_codification, piece_taken_enemy_codification, promotion?}
// --> piece_taken_my_codification - the codification is for an enemy piece (11 - 17 with 0 for no piece taken) as the piece is relative to the attacker
// --> promotion? - if there was a promotion of a pawn
// structure of move: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
// --> src_x, src_y, dst_x, dst_y - src and dst are as we are making the move so we want to move from dst to the src position the piece
// p_board - personal chess board 
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
inline void undo_move(std::vector<char> &info, std::vector<char> &move,
std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

// check for the promotion of pawns
inline
void check_promotion(std::vector<char> &info, std::vector<char> &move,
std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board);

inline
void undo_promotion(std::vector<char> &info, std::vector<char> &move,
std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board);

inline
void check_king_rook_swap(std::vector<char> &move,
std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board);

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

// a helper function to change info in the vector of pieces
inline void mv_piece_by_pos(const char old_x, const char old_y, const char new_x, const char new_y, std::vector<std::vector<char>> pieces);
#endif // GAME_H
