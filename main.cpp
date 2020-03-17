#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"

using namespace std;

int main() {
	// char c_in[50];
	// char c_out[50];
	// make_print_board_matrix(1);


 	// int force = 0; // case no force

	// signal (SIGTERM, SIG_IGN);
	// signal (SIGINT, SIG_IGN);

	cout.setf(ios::unitbuf);
	Log log;

	std::vector<std::pair<char, std::pair<char, char>>> playing_pieces_enemy;
	std::vector<std::pair<char, std::pair<char, char>>> playing_pieces_mine{
		std::make_pair(1, std::make_pair(1, 0)), std::make_pair(3, std::make_pair(0, 1))};

	std::vector<std::pair<char, char>> pawn_moves{
		std::make_pair(3, 0), std::make_pair(4, 0), std::make_pair(5, 0), std::make_pair(6, 0)};
	std::vector<std::pair<char, char>> knight_moves{
		std::make_pair(2, 0), std::make_pair(4, 1), std::make_pair(6, 0), std::make_pair(5, 2)};
	

	char wb = 1, force = 0, x_s = 0, y_s = 0, x_d = 0, y_d = 0; // engine default is black
	int pawn_move = 0, knight_move = 0; // we start to move with the pawn
	std::vector<std::vector<char>> chess_board;

	make_print_board_matrix(wb);
	protocol_begin(log); // we try to make the configuratinos here
	chess_board = get_initial_board_matrix();

	int passes = 0;

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
	    } else if (s.compare("time") == 0) {
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
	    	log.write("Received: we got the move ");
	    	log.write(s);
	    	log.write("\nmove ");
	    	get_matrix_coordonates(s, x_s, y_s); // now we have in x_s and y_s the coordonates of the source of the moved piece
	    	s = s.substr(2, 2); // we take the chess destinations on the board
	    	get_matrix_coordonates(s, x_d, y_d); // now we have in x_d and y_d the coordonates of the destination of the moved piece
	    	move_piece(x_s, y_s, x_d, y_d, chess_board, playing_pieces_mine);

	    	if (pawn_move != -1) {
	    		if (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 1) { // we move the pawn if exists
	    			std::cout << "move " << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second)
	    			<< get_chess_coordonates(pawn_moves[pawn_move].first, pawn_moves[pawn_move].second) << std::endl;
	    			
	    			log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second));
	    			log.write(get_chess_coordonates(pawn_moves[pawn_move].first, pawn_moves[pawn_move].second));
	    			log.write("\n");
	    			
	    			move_piece(playing_pieces_mine[0].second.first,
	    				playing_pieces_mine[0].second.second,
	    				pawn_moves[pawn_move].first,
	    				pawn_moves[pawn_move].second,
	    				chess_board, playing_pieces_mine);
	    			++pawn_move;
	    		} else if (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 3) { // we move the knight if exists
	    			pawn_move = -1;
	    			std::cout << "move" << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second)
	    			<< get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second) << std::endl;

	    			log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second));
	    			log.write(get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second));
	    			log.write("\n");

	    			move_piece(playing_pieces_mine[0].second.first,
	    				playing_pieces_mine[0].second.second,
	    				knight_moves[knight_move].first,
	    				knight_moves[knight_move].second,
	    				chess_board, playing_pieces_mine);
	    			++knight_move;
	    		} else {
	    			log.write("\n\tWOT???\n");
	    		}
	    	} else if (knight_move != -1 && (!playing_pieces_mine.empty() && playing_pieces_mine[0].first == 3)) { // we move the knight if exists
	    		std::cout << "move" << get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second)
	    		<< get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second) << std::endl;

	    		log.write(get_chess_coordonates(playing_pieces_mine[0].second.first, playing_pieces_mine[0].second.second));
	    		log.write(get_chess_coordonates(knight_moves[knight_move].first, knight_moves[knight_move].second));
	    		log.write("\n");

	    		move_piece(playing_pieces_mine[0].second.first,
	    				playing_pieces_mine[0].second.second,
	    				knight_moves[knight_move].first,
	    				knight_moves[knight_move].second,
	    				chess_board, playing_pieces_mine);
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




			/*if (wb == 0){
				if (knight_move < 3) {
					std::cout<<white_moves[knight_move]<<std::endl;
					knight_move++;
				} else {
					std::cout<<"resign"<<std::endl;;
					break;
				}
			} else if (knight_move < 3) {
				std::cout<<black_moves[move]<<std::endl;
				knight_move++;
			} else {
				std::cout<<"resign"<<std::endl;;
				break;
			}*/
		} else {
			std::cin >>  s;
			log.write(" ");
			log.write(s);
			break;
		}

		log.write("\npasses: ");
		log.write(std::to_string(passes));
		log.write("\n");
		++passes;
	}

	return 0;
}
