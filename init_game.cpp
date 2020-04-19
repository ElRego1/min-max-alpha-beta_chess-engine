/*

0 - empty sapce                      |
1 - my pawn   =   PAWN_M             | 11 - enemy pawn = PAWN_E
2 - my rook   =   ROOK_M             | 12 - enemy rook = ROOK_E
3 - my knight   =   KNIGHT_M         | 13 - enemy knight = KNIGHT_E
4 - my black bishop = BLACK_BISHOP_M | 14 - enemy black bishop = BLACK_BISHOP_E
5 - my white bishop = WHITE_BISHOP_M | 15 - enemy white bishop = WHITE_BISHOP_E
6 - my queen   =   QUEEN_M           | 16 - enemy queen = QUEEN_E
7 - my king   =   KING_M             | 17 - enemy king = KING_E

color: 0 - white = WHITE
       1 - black = BLACK

*/

#include "init_game.h"

// the matrix that is the actual board
std::vector<std::vector<char>> get_initial_board_matrix(char _color) {
	std::vector<std::vector<char>> v(BOX_LENGTH,
		std::vector<char>(BOX_LENGTH, 0));

	// put the pawns
	for (int i = 0; i < BOX_LENGTH; ++i) {
		v[1][i] = PAWN_M;
		v[6][i] = PAWN_E;
	}

	// put the rooks
	v[0][0] = ROOK_M; // mine
	v[0][7] = ROOK_M; // mine
	v[7][0] = ROOK_E; // enemy's
	v[7][7] = ROOK_E; // enemy's

	// put the knights
	v[0][1] = KNIGHT_M; // mine
	v[0][6] = KNIGHT_M; // mine
	v[7][1] = KNIGHT_E; // enemy's
	v[7][6] = KNIGHT_E; // enemy's

	// put the bishops
	v[0][2] = BLACK_BISHOP_M; // mine black
	v[0][5] = WHITE_BISHOP_M; // mine white
	v[7][2] = WHITE_BISHOP_E; // enemy's white
	v[7][5] = BLACK_BISHOP_E; // enemy's black

	// the position of the king and queen depends on the color
	if (_color == WHITE) { //play as white
		v[0][3] = QUEEN_M; // my queen
		v[0][4] = KING_M; // my king
		v[7][3] = QUEEN_E; // enemy's queen
		v[7][4] = KING_E; // enemy's king
	} else { // play as black
		v[0][3] = KING_M; // my king
		v[0][4] = QUEEN_M; // my queen
		v[7][3] = KING_E; // enemy's king
		v[7][4] = QUEEN_E; // enemy's queen
	}
	return v;
}

// a vector with the pieces
std::vector<std::vector<char>> get_initial_positions(char _color) {
	std::vector<std::vector<char>> p(NO_PIECES, std::vector<char>(NO_COORD + 1, 0));
		// pawns positions
		for (int i = 0; i < BOX_LENGTH; ++i) {
			p[i][0] = 1; // mine
			p[i][1] = i;
			p[i][2] = PAWN_M;
			// p[2 * BOX_LENGTH + i][0] = 6;
			// p[2 * BOX_LENGTH + i][1] = i;
		}

		// rooks positions
		p[BOX_LENGTH + 0][0] = 0;
		p[BOX_LENGTH + 0][1] = 0;
		p[BOX_LENGTH + 0][2] = ROOK_M;
		p[BOX_LENGTH + 1][0] = 0;
		p[BOX_LENGTH + 1][1] = 7;
		p[BOX_LENGTH + 1][2] = ROOK_M;

		// p[3 * BOX_LENGTH + 0][0] = 7;
		// p[3 * BOX_LENGTH + 0][1] = 0;
		// p[3 * BOX_LENGTH + 1][0] = 7;
		// p[3 * BOX_LENGTH + 1][1] = 7;

		// knights positions
		p[BOX_LENGTH + 2][0] = 0;
		p[BOX_LENGTH + 2][1] = 1;
		p[BOX_LENGTH + 2][2] = KNIGHT_M;
		p[BOX_LENGTH + 3][0] = 0;
		p[BOX_LENGTH + 3][1] = 6;
		p[BOX_LENGTH + 3][2] = KNIGHT_M;

		// p[3 * BOX_LENGTH + 2][0] = 7;
		// p[3 * BOX_LENGTH + 2][1] = 1;
		// p[3 * BOX_LENGTH + 3][0] = 7;
		// p[3 * BOX_LENGTH + 3][1] = 6;

		// bishops positions
		// mine black
		p[BOX_LENGTH + 4][0] = 0;
		p[BOX_LENGTH + 4][1] = 2;
		p[BOX_LENGTH + 4][2] = BLACK_BISHOP_M;
		// mine white
		p[BOX_LENGTH + 5][0] = 0;
		p[BOX_LENGTH + 5][1] = 5;
		p[BOX_LENGTH + 5][2] = WHITE_BISHOP_M;
		// // enemy's black
		// p[3 * BOX_LENGTH + 4][0] = 7;
		// p[3 * BOX_LENGTH + 4][1] = 5;
		// // enemy's white
		// p[3 * BOX_LENGTH + 5][0] = 7;
		// p[3 * BOX_LENGTH + 5][1] = 2;

		// king & queen positions
		// the position of the king and queen depends on the color
		if (_color == 0) { //play as white
			p[BOX_LENGTH + 6][0] = 0; // my queen
			p[BOX_LENGTH + 6][1] = 3; // my queen
			p[BOX_LENGTH + 6][2] = QUEEN_M; // my queen
			p[BOX_LENGTH + 7][0] = 0; // my king
			p[BOX_LENGTH + 7][1] = 4; // my king
			p[BOX_LENGTH + 7][2] = KING_M; // my king

			// p[3 * BOX_LENGTH + 6][0] = 7; // enemy's queen
			// p[3 * BOX_LENGTH + 6][1] = 3; // enemy's queen
			// p[3 * BOX_LENGTH + 7][0] = 7; // enemy's king
			// p[3 * BOX_LENGTH + 7][1] = 4; // enemy's king

		} else { // play as black
			p[BOX_LENGTH + 6][0] = 0; // my queen
			p[BOX_LENGTH + 6][1] = 4; // my queen
			p[BOX_LENGTH + 6][2] = QUEEN_M; // my queen
			p[BOX_LENGTH + 7][0] = 0; // my king
			p[BOX_LENGTH + 7][1] = 3; // my king
			p[BOX_LENGTH + 7][2] = KING_M; // my king

			// p[3 * BOX_LENGTH + 6][0] = 7; // enemy's queen
			// p[3 * BOX_LENGTH + 6][1] = 4; // enemy's queen
			// p[3 * BOX_LENGTH + 7][0] = 7; // enemy's king
			// p[3 * BOX_LENGTH + 7][1] = 3; // enemy's king
		}

		return p;
}

// saves the made print board into the variable print_board
void make_print_board_matrix(Game &g, char color) {
	std::vector<std::vector<char*>> p(BOX_LENGTH, std::vector<char*>(BOX_LENGTH));
	// if color is different from -1, we are at the first run and do not free the memory
	if (g.m_color != NO_COLOR) {
		for (char i = 0; i < BOX_LENGTH; ++i) {
			for (char j = 0; j < BOX_LENGTH; ++j) {
				free(g._print_board[i][j]);
			}
		}
	}

	g.m_color = color;

	if (color == WHITE) { // white
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
	g._print_board = p;
}

