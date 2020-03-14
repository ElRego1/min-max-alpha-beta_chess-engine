// functions to convert from the chess coordonates to our coordonates
// depending on the collor we play as

#ifndef MATRIX_TRANSFORMATIONS_H
#define MATRIX_TRANSFORMATIONS_H

#include <bits/stdc++.h>

extern char _collor;
extern std::vector<std::vector<char*>> _print_board;

[[gnu::always_inline]] 
std::string get_chess_coordonates(char x, char y);

[[gnu::always_inline]] 
void get_matrix_coordonates(std::string input, char x, char y);

#endif