#ifndef MINIMAX_H
#define MINIMAX_H

#include <bits/stdc++.h>
#include "game.h"
#include "constants.h"
#include "pieces.h"

class Game;

int alphabeta_maxi(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_m(Game &g); // calls get_moves from my perspective

int alphabeta_mini(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_e(Game &g); // calls get_moves from the enemy's perspective

std::vector<std::vector<char>> get_moves(std::vector<std::vector<char>> &pieces, std::vector<std::vector<char>> &board);

// structure of the paramether {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
// order descending by the priority of the piece that can be taken and if priority is equal, order ascending by the type of piece doing the attack
bool order_moves_by_priority(const std::vector<char> &a, const std::vector<char> &b);

// p_board - personal chess board
// p_pieces - personal vector with pieces
// h_board - hostile chess board
// h_pieces - hostile vector with pieces
// return value: the score of the game for the personal chess board that is relative
int evaluate(std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces);
int get_score(const int &piece_type);

#endif // MINIMAX_H
