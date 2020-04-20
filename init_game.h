/*

0 - empty sapce      |
1 - my pawn          | 11 - enemy pawn
2 - my rook          | 12 - enemy rook
3 - my knight        | 13 - enemy knight
4 - my black bishop  | 14 - enemy black bishop
5 - my white bishop  | 15 - enemy white bishop
6 - my queen         | 16 - enemy queen
7 - my king          | 17 - enemy king

color: 0 - white
       1 - black

*/

#ifndef INIT_GAME_H
#define INIT_GAME_H

#include <bits/stdc++.h>
#include "constants.h"
#include "game.h"

// the matrix that is the actual board
std::vector<std::vector<char>> get_initial_board_matrix(char _color);

// a vector with the pieces
std::vector<std::vector<char>> get_initial_positions(char _color);

// saves the made print board into the variable print_board
void make_print_board_matrix(Game &g, char color);

#endif // INIT_GAME_H
