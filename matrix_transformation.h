// functions to convert from the chess coordonates to our coordonates
// depending on the collor we play as

#ifndef MATRIX_TRANSFORMATIONS_H
#define MATRIX_TRANSFORMATIONS_H

#include <bits/stdc++.h>
#include "constants.h"
#include "game.h"

std::string get_chess_coordonates(char x, char y, Game &g);

void get_matrix_coordonates(std::string &input, char &x, char &y, Game &g);

// changes the matrix coordonates from the personal point of view to enemy's point of view and vice versa
void change_coordonates(const char &fst_x, const char &fst_y, char &snd_x, char &snd_y);


#endif
