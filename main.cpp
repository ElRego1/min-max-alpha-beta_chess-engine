#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"

int main() {

	Log log;
	make_print_board_matrix(1);

	protocol_begin(log);
	// char x, y;
	// std::string s = "a1";
	// get_matrix_coordonates(s, x, y);

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