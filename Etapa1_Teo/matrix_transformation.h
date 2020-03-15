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
	char letter = input[0];
	// std::cout << "letter: " << letter << " "; 
	char number = input[1];
	// std::cout << "number: " << number << "\n";
	switch(letter) {
		case 'a': y = 0; break;
		case 'b': y = 1; break;
		case 'c': y = 2; break;
		case 'd': y = 3; break;
		case 'e': y = 4; break; 
		case 'f': y = 5; break;
		case 'g': y = 6; break;
		case 'h': y = 7; break;
		default: y = -1; // should never reach here
	}
	switch(number) {
		case '1': x = 0; break;
		case '2': x = 1; break;
		case '3': x = 2; break;
		case '4': x = 3; break;
		case '5': x = 4; break; 
		case '6': x = 5; break;
		case '7': x = 6; break;
		case '8': x = 7; break;
		default: x = -1; // should never reach here
	}
	
	// if we are playing black, we have to convert to the black coordonates
	if (_collor == 1) {
		x = 7 - x;
		y = 7 - y;
	}
}


#endif