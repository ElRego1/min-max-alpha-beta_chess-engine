#include "matrix_transformation.h"

std::string get_chess_coordonates(char x, char y, Game &g) {
	return std::string(g._print_board[x][y]);
}

void get_matrix_coordonates(std::string &input, char &x, char &y, Game &g) {
	x = input[1] - '1';
  	y = input[0] - 'a';

	// if we are playing black, we have to convert to the black coordonates
	if (g.m_color == WHITE) {
		x = 7 - x;
		y = 7 - y;
	}

	if (x < 0 || y < 0 || x >= BOX_LENGTH || y >= BOX_LENGTH) {
		fprintf(stderr, "Error at transforming the parameters... x: %d | y: %d\n", x, y);
	}
}

// changes the matrix coordonates from the personal point of view to enemy's point of view and vice versa
void change_coordonates(const char &fst_x, const char &fst_y, char &snd_x, char &snd_y) {
	snd_x = 7 - fst_x;
	snd_y = 7 - fst_y;
}
