#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"

int main() {
	char c_in[50];
	char c_out[50];

	Log log;

	while (1) {
		std::cout << "A2A3" << std::endl;
		log.write("sent: A2A3\n");

		std::cin >> c_in;
		sprintf(c_out, "received: %s\n", c_in);
		log.write(c_out);
		
		memset(c_in, 0, sizeof(c_in));
		memset(c_out, 0, sizeof(c_out));

	}

	return 0;
}