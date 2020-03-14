#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"

int main() {
	char c_in[50];
	char c_out[50];
	make_print_board_matrix(0);

	char x = 2;
	char y = 4;

	std::string s = get_chess_coordonates(x, y);
	// std::cout << get_chess_coordonates(x, y);

	// Log log;

	// while (1) {
	// 	std::cout << "A2A3" << std::endl;
	// 	log.write("sent: A2A3\n");

	// 	std::cin >> c_in;
	// 	sprintf(c_out, "received: %s\n", c_in);
	// 	log.write(c_out);
		
	// 	memset(c_in, 0, sizeof(c_in));
	// 	memset(c_out, 0, sizeof(c_out));

	// }

	return 0;
}