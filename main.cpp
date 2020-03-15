#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"

using namespace std;

int main() {
	char c_in[50];
	char c_out[50];
	// make_print_board_matrix(1);

	Log log;
  int force = 0; // case no force
  int wb = 0; // case white engine (1->>black engine)

	signal (SIGTERM, SIG_IGN);
	signal (SIGINT, SIG_IGN);

	char x = 2;
	char y = 4;
	cout.setf(ios::unitbuf);

	// std::string s = get_chess_coordonates(x, y);
	//std::cout << get_chess_coordonates(x, y) << "\n";

	//std:: string input = "g6";
	//get_matrix_coordonates(input, x, y);
	//std::cout << "x: " << (int)x << " y: " << (int)y << "\n";
	// int x_int = x;
	// int y_int = y;
	// std::cout << "x: " << x_int << " y: " << y_int << "\n";
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

	//std::vector<std::vector<char>> white_moves;
	//std::vector<std::vector<char>> black_moves;
	string white_moves[3] = {"move g1f3", "move f3h4", "move h4g6"};
	string black_moves[3] = {"move b8c6", "move c6a5", "move a5b3"};
	//white_moves = {"g1f3", "f3h4", "h4g6"};
	//black_moves = {"b8c6", "c6a5", "a5b3"};

	int move = 0;
	while(true){
		std::string s;
    std::cin>>s;
    log.write(s);
    log.write("\n");
    if (s.compare("xboard") == 0) {
        std::cout<<"\n";
        log.write("\n");
    } else if (s.compare("protover") == 0) {
        std::cin>>s; // reading N
        log.write(s);
        std::cout<<"feature done=1"<<std::endl;
        log.write("feature done=1");
    } else if (s.compare("new") == 0) {
        wb = 1;
        force = 0;
				get_initial_board_matrix();
				make_print_board_matrix(wb);
        //TODO
    } else if (s.compare("force") == 0) {
        force = 1;
        //TODO
    } else if (s.compare("go") == 0) {
        force = 0;
        //TODO
    } else if (s.compare("white") == 0) {
        wb = 1;
				make_print_board_matrix(wb);
        //TODO
    } else if (s.compare("black") == 0) {
        wb = 0;
				make_print_board_matrix(wb);
        //TODO
    } else if (s.compare("quit") == 0) {
        //SIGTERM does the job
    } else if (s.compare("resign") == 0) {
				//TODO
    }
      //TODO case move
    else if (!isdigit(s[0]) && isdigit(s[1])) {
					if (wb == 0){
						if (move < 3) {
							std::cout<<white_moves[move]<<std::endl;
							move++;
						} else {
								std::cout<<"resign"<<std::endl;;
								break;
							}
					} else if (move < 3) {
							std::cout<<black_moves[move]<<std::endl;
							move++;
						} else {
								std::cout<<"resign"<<std::endl;;
								break;
							}
					}
          //std::cout<<"move b8a6\n";
          //log.write("move b8a6\n");
	}




	return 0;
}
