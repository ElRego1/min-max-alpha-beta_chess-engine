#ifndef MINIMAX_H
#define MINIMAX_H

#include <bits/stdc++.h>
#include "game.h"
#include "constants.h"
#include "pieces.h"

int alphabeta_maxi(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_m(Game &g); // calls get_moves from my perspective

int alphabeta_mini(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_e(Game &g); // calls get_moves from the enemy's perspective

std::vector<std::vector<char>> get_moves(std::vector<std::vector<char>> &pieces, std::vector<std::vector<char>> &board);

// p_board - personal chess board 
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
// return value: the score of the game for the personal chess board that is relative
int evaluate(std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);

#endif // MINIMAX_H