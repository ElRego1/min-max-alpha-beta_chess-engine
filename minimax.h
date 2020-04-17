#ifndef MINIMAX_H
#define MINIMAX_H

#include <bits/stdc++.h>
#include "constants.h"
#include "pieces.h"
#include "game.h"

int alphabeta_maxi(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_m(Game &g);

int alphabeta_mini(int depth, int alpha, int beta, Game &g);
std::vector<std::vector<char>> get_moves_e(Game &g);

int evaluate();

#endif // MINIMAX_H