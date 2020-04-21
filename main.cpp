#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"
#include "constants.h"
#include "game.h"

using namespace std;

int main() {

	cout.setf(ios::unitbuf);
	Log log;

	char wb = BLACK, force = 0, x_s = 0, y_s = 0, x_d = 0, y_d = 0; // engine default is black
	int primit_culoare = 0;
	Game g(wb);

	std::vector<std::vector<char>> chess_board = g.m_board;
	std::vector<std::vector<char>> positions = g.m_pieces;

	protocol_begin(log); // we try to make the configuratinos here

	int passes = 0;
	int idx_move = 0;

	while(true){
		log.write("\npasses: ");
		log.write(std::to_string(passes));
		log.write("\n");

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
	        std::cout<<"feature done=1 sigterm=0 san=0"<<std::endl;
	        log.write("feature done=1 sigterm=0 san=0");
	    } else if (s.compare("new") == 0) {
	        wb = 1;
	        force = 0;
					g.remake_print_board(wb);
	    } else if (s.compare("force") == 0) {
	        //force = 1;
					//g.remake_print_board(wb);
	    } else if (s.compare("go") == 0) {
	        force = 0;
					// if (idx_move % 2 == 1) {
					// 	goto black_engine;
					// } else {
					// 	goto white_engine;
					// }
	    } else if (s.compare("white") == 0 && primit_culoare == 0) {
black_engine:
	        wb = 1;
					g.remake_print_board(wb);
					primit_culoare = 1;
	    }	else if (s.compare("black") == 0 && primit_culoare == 0 && idx_move == 0) {
// white_engine:
					primit_culoare = 1;
	        wb = 0;
					g.remake_print_board(wb);
					// if (wb == 0 && move == 0 && force == 0) {
					// 	std::cout<<white_moves[move]<<std::endl;
					// 	move++;
					// 	continue;
					// }
					std::vector<char> mymove;
					mymove = g.find_next_move();
					if (mymove.size() != 0) {

						std::vector<char> mymove_chr2;
						mymove_chr2.push_back(mymove[0]);
						mymove_chr2.push_back(mymove[1]);
						mymove_chr2.push_back(mymove[2]);
						mymove_chr2.push_back(mymove[3]);
						g.apply_move_m(mymove_chr2);

						std::string mymove_str = get_chess_coordonates(mymove[0], mymove[1], g) + get_chess_coordonates(mymove[2], mymove[3], g);
						std::string mymove_command = "move " + mymove_str;
						std::cout<<mymove_command<<std::endl;
						++idx_move;
					} else {
						log.write("resign\n");
			    	std::cout<<"resign\n";
						break;
					}
	    } else if (s.compare("quit") == 0) {
					break;
	    } else if (s.compare("resign") == 0) {
					break;

			} else if (force == 1 && !isdigit(s[0]) && isdigit(s[1])) {
					//std::cin >> s;
					get_matrix_coordonates(s, x_s, y_s, g); // now we have in x_s and y_s the coordonates of the source of the moved piece
		    		s = s.substr(2, 2); // we take the chess destinations on the board
		    		get_matrix_coordonates(s, x_d, y_d, g); // now we have in x_d and y_d the coordonates of the destination of the moved piece
					idx_move++;

	    } else if (s.compare("time") == 0 && force == 0) {
	    	std::cin >> s;
	    	log.write(s);
	    	log.write(" ");

	    	std::cin >> s;
	    	log.write(s);
	    	log.write(" ");
	    	std::cin >> s; // we finished with reading the time and now we will read the value for the matrix
	    	log.write(s);
	    	log.write(" ");

	    	std::cin >> s; // we read the opponent's move
				if (s.compare("white") == 0){
					// goto white_engine;
					std::cin >> s;
					std::cin >> s;
					std::cin >> s;
					//goto citit;
					std::cin >> s;
					std::cin >> s;
					std::cin >> s;
				}
				if (s.compare("black") == 0){
					goto black_engine;
					// std::cin >> s;
					// std::cin >> s;
					// std::cin >> s;
					// //goto citit;
					// std::cin >> s;
					// std::cin >> s;
					// std::cin >> s;
				}

	    	log.write("Received: we got the move ");
	    	log.write(s);
	    	log.write("\nmove ");

	    	get_matrix_coordonates(s, x_s, y_s, g); // now we have in x_s and y_s the coordonates of the source of the moved piece
	    	s = s.substr(2, 2); // we take the chess destinations on the board
	    	get_matrix_coordonates(s, x_d, y_d, g); // now we have in x_d and y_d the coordonates of the destination of the moved piece

				++idx_move;
				std::vector<char> mymove_chr;
				mymove_chr.push_back(x_s);
				mymove_chr.push_back(y_s);
				mymove_chr.push_back(x_d);
				mymove_chr.push_back(y_d);
				
				g.apply_move_e(mymove_chr);

				std::vector<char> mymove;
				mymove = g.find_next_move();
				if (mymove.size() != 0) {

					std::vector<char> mymove_chr2;
					mymove_chr2.push_back(mymove[0]);
					mymove_chr2.push_back(mymove[1]);
					mymove_chr2.push_back(mymove[2]);
					mymove_chr2.push_back(mymove[3]);
					g.apply_move_m(mymove_chr2);

					std::string mymove_str = get_chess_coordonates(mymove[0], mymove[1], g) + get_chess_coordonates(mymove[2], mymove[3], g);
					std::string mymove_command = "move " + mymove_str;
					std::cout<<mymove_command<<std::endl;
					++idx_move;
				} else {
					log.write("resign\n");
		    	std::cout<<"resign\n";
					break;
				}

		}

		log.write("\npasses: ");
		log.write(std::to_string(passes));
		log.write("\n");
		++passes;
	}

	return 0;
}
