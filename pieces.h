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

int check_validity(char i, char j);
std::vector<std::vector<char>> get_piece_directions(char p);
void move_piece(char x_s, char y_s, char x_d, char y_d,
	std::vector<std::vector<char>> &chess_board,
	std::vector<std::pair<char, std::pair<char, char>>> &playing_pieces_mine);


#endif // PIECES_H
