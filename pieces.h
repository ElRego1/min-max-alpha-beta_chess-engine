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
#include "constants.h"
std::pair<char, char> lp_m( 1, -1);
std::pair<char, char> rp_m( 1,  1);
std::vector<std::pair<char, char>> m_pawn_attack_directions{lp_m, rp_m};
std::pair<char, char> lp_e(-1, -1);
std::pair<char, char> rp_e(-1,  1);
std::vector<std::pair<char, char>> e_pawn_attack_directions{lp_e, rp_e};
// | ++++ | ++++ | ++++ | ++++ | ++++ |
// |      |      |      |      |      |
// |      |      |      | PAWN |      | --> enemy pawn
// |      |      | lp_e |      | rp_e | --> attack positions
// |      |      |      |      |      |
// |      |      |      |      |      |
// |      |      |      |      |      |
// |      |      |      |      |      |
// | lp_m |      | rp_m |      |      | --> attack positions
// |      | pawn |      |      |      | --> my pawn
// |      |      |      |      |      |
// | ++++ | ++++ | ++++ | ++++ | ++++ |

std::pair<char, char> ur_k( 2,  1); // explanation of the positions by name
std::pair<char, char> ru_k( 1,  2); // | ++++ | ++++ | ++++ | ++++ | ++++ |
std::pair<char, char> rd_k(-1,  2); // |      | ul_k |      | ur_k |      |
std::pair<char, char> dr_k(-2,  1); // | lu_k |      |      |      | ru_k |
std::pair<char, char> dl_k(-2, -1); // |      |      |knight|      |      |
std::pair<char, char> ld_k(-1, -2); // | ld_k |      |      |      | rd_k |
std::pair<char, char> lu_k( 1, -2); // |      | dl_k |      | dr_k |      |
std::pair<char, char> ul_k( 2, -1); // | ++++ | ++++ | ++++ | ++++ | ++++ |
std::vector<std::pair<char, char>> knight_directions{ur_k, ru_k, rd_k, dr_k, dl_k, ld_k, lu_k, ul_k};

std::pair<char, char> up( 1,  0); // up
std::pair<char, char> dw(-1,  0); // down
std::pair<char, char> rg( 0,  1); // right
std::pair<char, char> lf( 0, -1); // left
std::pair<char, char> ur( 1,  1); // up-right
std::pair<char, char> ul( 1, -1); // up-left
std::pair<char, char> dr(-1,  1); // down-right
std::pair<char, char> dl(-1, -1); // down-left
std::vector<std::pair<char, char>> all_directions{up, dw, rg, lf, ur, ul, dr, dl};


int check_validity(char i, char j, std::vector<std::vector<char>> &chess_board);
int check_validity_pawn(char i, char j, std::vector<std::vector<char>> &chess_board);

std::vector<char> get_piece_position(char p, int d, std::vector<std::vector<char>> &positions);
std::vector<std::vector<char>> get_piece_directions(char i, char j, std::vector<std::vector<char>> &chess_board);

// std::vector<char> move_piece(char x_s, char y_s, char x_d, char y_d,
//         std::vector<std::vector<char>> &positions,
//         std::vector<std::vector<char>> &e_positions,
//         std::vector<std::vector<char>> &chess_board);

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
