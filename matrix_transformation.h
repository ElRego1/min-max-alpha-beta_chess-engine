// functions to convert from the chess coordonates to our coordonates
// depending on the collor we play as

#ifndef MATRIX_TRANSFORMATIONS_H
#define MATRIX_TRANSFORMATIONS_H

#include <bits/stdc++.h>

extern char _collor;
extern std::vector<std::vector<char*>> _print_board;

[[gnu::always_inline]] inline
std::string get_chess_coordonates(char x, char y) {
	return std::string(_print_board[x][y]);
}

[[gnu::always_inline]] inline
void get_matrix_coordonates(std::string &input, char &x, char &y) {
	x = input[1] - '1';
    y = input[0] - 'a';
	
	// if we are playing black, we have to convert to the black coordonates
	if (_color == 1) {
		x = 7 - x;
		y = 7 - y;
	}

	if (x < 0 || y < 0 || x >= BOX_LENGTH || y >= BOX_LENGTH) {
		fprintf(stderr, "Error at transforming the parameters... x: %d | y: %d\n", x, y);
	}
}


#endif