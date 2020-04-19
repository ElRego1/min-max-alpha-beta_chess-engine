#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"
#include "constants.h"

using namespace std;

int main() {

	cout.setf(ios::unitbuf);
	Log log;

	std::vector<std::pair<char, std::pair<char, char>>> playing_pieces_enemy;
	std::vector<std::pair<char, std::pair<char, char>>> playing_pieces_mine{
		std::make_pair(1, std::make_pair(1, 0)), std::make_pair(3, std::make_pair(0, 1))};

	std::vector<std::pair<char, char>> pawn_moves{
		std::make_pair(3, 0), std::make_pair(4, 0), std::make_pair(5, 0), std::make_pair(6, 0)};
	std::vector<std::pair<char, char>> knight_moves{
		std::make_pair(2, 0), std::make_pair(4, 1), std::make_pair(6, 0), std::make_pair(5, 2)};

	std::string white_moves[3] = {"move g1f3", "move f3h4", "move h4g6"};
	int move = 0;


	char wb = 1, force = 0, x_s = 0, y_s = 0, x_d = 0, y_d = 0; // engine default is black
	int pawn_move = 0, knight_move = 0; // we start to move with the pawn

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
	        std::cout<<"feature done=1"<<std::endl;
	        log.write("feature done=1");
	    } else if (s.compare("new") == 0) {
	        wb = 1;
	        force = 0;
					g.remake_print_board(wb);
	    } else if (s.compare("force") == 0) {
	        force = 1;
					g.remake_print_board(wb);
	    } else if (s.compare("go") == 0) {
	        force = 0;
					if (idx_move % 2 == 1 || idx_move == 0) {
							goto black_engine;
					} else {
							goto white_engine;
					}
	    } else if (s.compare("white") == 0) {
black_engine:
	        wb = 1;
					g.remake_print_board(wb);
	    }	else if (s.compare("black") == 0) {
white_engine:
	        wb = 0;
					g.remake_print_board(wb);
					if (wb == 0 && move == 0 && force == 0) {
						std::cout<<white_moves[move]<<std::endl;
						move++;
						continue;
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
		    		// move_piece(x_s, y_s, x_d, y_d, chess_board, playing_pieces_mine);
					//std::cout << "move b6b5" << '\n';
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
					goto white_engine;
				}
				if (s.compare("black") == 0){
					goto black_engine;
				}

	    	log.write("Received: we got the move ");
	    	log.write(s);
	    	log.write("\nmove ");
	    	get_matrix_coordonates(s, x_s, y_s, g); // now we have in x_s and y_s the coordonates of the source of the moved piece
	    	s = s.substr(2, 2); // we take the chess destinations on the board
	    	get_matrix_coordonates(s, x_d, y_d, g); // now we have in x_d and y_d the coordonates of the destination of the moved piece
	    	// std::cout << "# x_s: " << (int)x_s << " | y_s: " << (int)y_s << " | x_d: " << (int)x_d << " | y_d: " << (int)y_d << "\n";
	    	// move_piece(x_s, y_s, x_d, y_d, chess_board, playing_pieces_mine);

				if (wb == 1) {
		    	if (pawn_move != -1) {
		    		if (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 1) { // we move the pawn if exists
		    			// check if pawn can move forward
		    			if (chess_board[pawn_moves[pawn_move].first][pawn_moves[pawn_move].second] != 0) {
		    				x_s = playing_pieces_mine[0].second.first;
		    				y_s = playing_pieces_mine[0].second.second;

		    				std::vector<std::pair<char, std::pair<char, char>>>::iterator it
                				= std::find(playing_pieces_mine.begin(), playing_pieces_mine.end(),
				                std::pair<char, std::pair<char, char>>(std::make_pair(
				                chess_board[x_s][y_s], std::make_pair(x_s, y_s))));
				            if (it != playing_pieces_mine.end()) {
				                playing_pieces_mine.erase(it);
				            }
				            pawn_move = -1;
				            goto pawn_cant_move;
		    			}

		    			std::cout << "move " << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g)
		    			<< get_chess_coordonates(pawn_moves[pawn_move].first, pawn_moves[pawn_move].second, g) << std::endl;

		    			log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g));
		    			log.write(get_chess_coordonates(pawn_moves[pawn_move].first, pawn_moves[pawn_move].second, g));
		    			log.write("\n");

		    			// move_piece(playing_pieces_mine[0].second.first,
		    			// 	playing_pieces_mine[0].second.second,
		    			// 	pawn_moves[pawn_move].first,
		    			// 	pawn_moves[pawn_move].second,
		    			// 	chess_board, playing_pieces_mine);
		    			++pawn_move;
		    		} else if (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 3) { // we move the knight if exists
pawn_cant_move:
		    			pawn_move = -1;
		    			std::cout << "move " << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g)
		    			<< get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second, g) << std::endl;

		    			log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g));
		    			log.write(get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second, g));
		    			log.write("\n");

		    			// move_piece(playing_pieces_mine[0].second.first,
		    			// 	playing_pieces_mine[0].second.second,
		    			// 	knight_moves[knight_move].first,
		    			// 	knight_moves[knight_move].second,
		    			// 	chess_board, playing_pieces_mine);
		    			++knight_move;
		    		} else {
		    			log.write("\n\tWOT???\n");
		    		}
		    	} else if (knight_move != -1 && (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 3)) { // we move the knight if exists
		    		std::cout << "move " << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g)
		    		<< get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second, g) << std::endl;

		    		log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second, g));
		    		log.write(get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second, g));
		    		log.write("\n");

		    		// move_piece(playing_pieces_mine[0].second.first,
		    		// 		playing_pieces_mine[0].second.second,
		    		// 		knight_moves[knight_move].first,
		    		// 		knight_moves[knight_move].second,
		    		// 		chess_board, playing_pieces_mine);
		    			++knight_move;
		    	} else {
		    		log.write("resign\n");
		    		std::cout<<"resign\n";
					break;
		    	}

		    	if (pawn_move == 4) {
		    		pawn_move = -1;
		    		playing_pieces_mine.erase(playing_pieces_mine.begin());
		    	} if (knight_move == 4) {
		    		knight_move = -1;
		    	}
			} else {
				if (move < 3) {
							std::cout<<white_moves[move]<<std::endl;
							move++;
						} else {
								log.write("resign\n");
								std::cout<<"resign"<<std::endl;;
								break;
							}
			}

			++idx_move;
		}

		log.write("\npasses: ");
		log.write(std::to_string(passes));
		log.write("\n");
		++passes;
	}

	return 0;
}
