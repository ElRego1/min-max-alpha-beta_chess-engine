/*

0 - empty sapce
1 - pawns
2 - the rook
3 - the knight
4 - the black bishop
5 - the white bishop
6 - the queen
7 - the king

*/

#ifndef PIECES_H
#define PIECES_H

#include <bits/stdc++.h>

#define BOX_SQUARES 64
#define BOX_LENGTH 8

extern std::vector<std::vector<char>> positions;

std::pair<char, char> up( 1,  0); // up
std::pair<char, char> dw(-1,  0); // down
std::pair<char, char> rg( 0,  1); // right
std::pair<char, char> lf( 0, -1); // left
std::pair<char, char> ur( 1,  1); // up-right
std::pair<char, char> ul( 1, -1); // up-left
std::pair<char, char> dr(-1,  1); // down-right
std::pair<char, char> dl(-1, -1); // down-left

int check_validity(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_validity_pawn(char i, char j, std::vector<std::vector<char>> &chess_board);

std::vector<char> get_piece_position(char p, int d, std::vector<std::vector<char>> &positions);
std::vector<std::vector<char>> get_piece_directions(char i, char j, std::vector<std::vector<char>> &chess_board);

std::vector<char> move_piece(char x_s, char y_s, char x_d, char y_d,
        std::vector<std::vector<char>> &positions,
        std::vector<std::vector<char>> &e_positions,
        std::vector<std::vector<char>> &chess_board);

// --------------------------------------------- Robert's attemp --------------------------------
void rook_moves(char &i, char &j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void bishop_moves(char &i, char &j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void get_direct_moves(char i, char j, std::pair<char, char> &d, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);

// --------------------------------------------- Teo's moves --------------------------------
void check_move_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void check_move_down(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void check_move_left(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void check_move_right(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);

void check_move(char i, char j, int i_depl, int j_depl, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);

// --------------------------------------------- diagonal moves --------------------------------
void right_diag_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void left_diag_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void right_diag_down(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);
void left_diag_down(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board);


#endif // PIECES_H
