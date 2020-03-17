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

#define BOX_SQUARES 64
#define BOX_LENGTH 8
#define NO_PIECES 32
#define NO_COORD 2

char _color = -1;
std::vector<std::vector<char*>> _print_board;
std::vector<std::vector<char>> positions;

char _color = -1;
std::vector<std::vector<char*>> _print_board;
std::vector<std::vector<char>> positions;



std::vector<std::vector<char>> get_initial_board_matrix() {
	std::vector<std::vector<char>> v(BOX_LENGTH,
		std::vector<char>(BOX_LENGTH, 0));

	// put the pawns
	for (int i = 0; i < BOX_LENGTH; ++i) {
		v[1][i] = 1;
		v[6][i] = 11;
	}

	// put the rooks
	v[0][0] = 2; // mine
	v[0][7] = 2; // mine
	v[7][0] = 12; // enemy's
	v[7][7] = 12; // enemy's

	// put the knights
	v[0][1] = 3; // mine
	v[0][6] = 3; // mine
	v[7][1] = 13; // enemy's
	v[7][6] = 13; // enemy's

	// put the bishops
	v[0][2] = 4; // mine black
	v[0][5] = 5; // mine white
	v[7][2] = 15; // enemy's white
	v[7][5] = 14; // enemy's black

	// the position of the king and queen depends on the color
	if (_color == 0) { //play as white
		v[0][3] = 6; // my queen
		v[0][4] = 7; // my king
		v[7][3] = 16; // enemy's queen
		v[7][4] = 17; // enemy's king
	} else { // play as black
		v[0][3] = 7; // my king
		v[0][4] = 6; // my queen
		v[7][3] = 17; // enemy's king
		v[7][4] = 16; // enemy's queen
	}
	return v;
}

std::vector<std::vector<char>> get_initial_positions() {
	std::vector<std::vector<char>> p(NO_PIECES,
		std::vector<char>(NO_COORD, 0));
		// pawns positions
		for (int i = 0; i < BOX_LENGTH; ++i) {
			p[i][0] = 1; // mine
			p[i][1] = i;
			p[2 * BOX_LENGTH + i][0] = 6;
			p[2 * BOX_LENGTH + i][1] = i;
		}

		// rooks positions
		p[BOX_LENGTH + 0][0] = 0;
		p[BOX_LENGTH + 0][1] = 0;
		p[BOX_LENGTH + 1][0] = 0;
		p[BOX_LENGTH + 1][1] = 7;

		p[3 * BOX_LENGTH + 0][0] = 7;
		p[3 * BOX_LENGTH + 0][1] = 0;
		p[3 * BOX_LENGTH + 1][0] = 7;
		p[3 * BOX_LENGTH + 1][1] = 7;

		// knights positions
		p[BOX_LENGTH + 2][0] = 0;
		p[BOX_LENGTH + 2][1] = 1;
		p[BOX_LENGTH + 3][0] = 0;
		p[BOX_LENGTH + 3][1] = 6;

		p[3 * BOX_LENGTH + 2][0] = 7;
		p[3 * BOX_LENGTH + 2][1] = 1;
		p[3 * BOX_LENGTH + 3][0] = 7;
		p[3 * BOX_LENGTH + 3][1] = 6;

		// bishops positions
		// mine black
		p[BOX_LENGTH + 4][0] = 0;
		p[BOX_LENGTH + 4][1] = 2;
		// mine white
		p[BOX_LENGTH + 5][0] = 0;
		p[BOX_LENGTH + 5][1] = 5;
		// enemy's black
		p[3 * BOX_LENGTH + 4][0] = 7;
		p[3 * BOX_LENGTH + 4][1] = 5;
		// enemy's white
		p[3 * BOX_LENGTH + 5][0] = 7;
		p[3 * BOX_LENGTH + 5][1] = 2;

		// king & queen positions
		// the position of the king and queen depends on the color
		if (_color == 0) { //play as white
			p[BOX_LENGTH + 6][0] = 0; // my queen
			p[BOX_LENGTH + 6][1] = 3; // my queen
			p[BOX_LENGTH + 7][0] = 0; // my king
			p[BOX_LENGTH + 7][1] = 4; // my king

			p[3 * BOX_LENGTH + 6][0] = 7; // enemy's queen
			p[3 * BOX_LENGTH + 6][1] = 3; // enemy's queen
			p[3 * BOX_LENGTH + 7][0] = 7; // enemy's king
			p[3 * BOX_LENGTH + 7][1] = 4; // enemy's king

		} else { // play as black
			p[BOX_LENGTH + 6][0] = 0; // my queen
			p[BOX_LENGTH + 6][1] = 4; // my queen
			p[BOX_LENGTH + 7][0] = 0; // my king
			p[BOX_LENGTH + 7][1] = 3; // my king

			p[3 * BOX_LENGTH + 6][0] = 7; // enemy's queen
			p[3 * BOX_LENGTH + 6][1] = 4; // enemy's queen
			p[3 * BOX_LENGTH + 7][0] = 7; // enemy's king
			p[3 * BOX_LENGTH + 7][1] = 3; // enemy's king
		}

		return p;
}

// saves the made print board into the variable print_board
void make_print_board_matrix(char color) {
	std::vector<std::vector<char*>> p(BOX_LENGTH,
		std::vector<char*>(BOX_LENGTH));
	// if color is different from -1, we are at the first run and do not free the memory
	if (_color != -1) {
		for (char i = 0; i < BOX_LENGTH; ++i) {
			for (char j = 0; j < BOX_LENGTH; ++j) {
				free(_print_board[i][j]);
			}
		}
	}

	_color = color;

	if (color == 0) { // white
		for (char number = '1'; number <= '8'; ++number) {
			for (char letter = 'a'; letter <= 'h'; ++letter) {
				p[number - '1'][letter - 'a'] = (char*)malloc(sizeof(char) * 3);
				p[number - '1'][letter - 'a'][0] = letter;
				p[number - '1'][letter - 'a'][1] = number;
				p[number - '1'][letter - 'a'][2] = 0; // \0
			}
		}
	} else { // black
		for (char number = '8'; number >= '1'; --number) {
			for (char letter = 'h'; letter >= 'a'; --letter) {
				p['8' - number]['h' - letter] = (char*)malloc(sizeof(char) * 3);
				p['8' - number]['h' - letter][0] = letter;
				p['8' - number]['h' - letter][1] = number;
				p['8' - number]['h' - letter][2] = 0; // \0
			}
		}
	}
	_print_board = p;
}

// TO_DO
// std::vector<char> make_board(char color) {
// 	std::vector<char> b(BOX_SQUARES);
// 	return b;
// }

#endif // INIT_GAME_H
