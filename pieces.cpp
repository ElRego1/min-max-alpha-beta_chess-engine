#include "pieces.h"

int check_validity(char i, char j) {
      if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0;
      return 1;
}

std::vector<std::vector<char>> get_piece_directions(char p, int d) {
    std::vector<std::vector<char>> possible_moves;
    char i, j; // piece positions;
    switch (p) {
        case 1: // pawn
            i = positions[d][0];
            j = positions[d][1];
            if (i == 6) {
                possible_moves[0][0] = 4;
                possible_moves[0][1] = j;
            } else {
                if (check_validity(i-1,j)) {
                    possible_moves[1][0] = i-1;
                    possible_moves[1][1] = j;
                }
            }
            break;
        case 2: // rook
            i = positions[8 + d][0];
            j = positions[8 + d][1];
            break;
        case 3: // knight
            i = positions[10 + d][0];
            j = positions[10 + d][1];
            break;
        case 4: // black bishop
            i = positions[12 + d][0];
            break;
        case 5: // white bishop
            i = positions[13 + d][0];
            break;
        case 6: // queen
            i = positions[14 + d][0];
            break;
        case 7: // king
            i = positions[15 + d][0];
            break;
        default:
            break;
    }
    // TODO a ramas nefacuta, ce ai facut teo? :)
    // return nullptr;
}

void move_piece(char x_s, char y_s, char x_d, char y_d,
    std::vector<std::vector<char>> &chess_board,
    std::vector<std::pair<char, std::pair<char, char>>> &playing_pieces_mine) {
    if (chess_board[x_s][y_s] == 0) {
        std::cout << "#probleme\n";
    }

    if (chess_board[x_s][y_s] < 10) { //it's my piece
        // a one liner to take the iterator to the position of my piece in the vector
        std::vector<std::pair<char, std::pair<char, char>>>::iterator it
            = std::find(playing_pieces_mine.begin(), playing_pieces_mine.end(),
            std::pair<char, std::pair<char, char>>(std::make_pair(
                chess_board[x_d][y_d], std::make_pair(x_d, y_d))));
        playing_pieces_mine[0].second.first = x_d;
        playing_pieces_mine[0].second.second = y_d;
        // (*it).second.first = x_d;
        // (*it).second.second = y_d;
        chess_board[x_d][y_d] = chess_board[x_s][y_s];
        chess_board[x_s][y_s] = 0;
        // TODO
        // take piece from the enemy
        // make the special move the rook and the king
    } else { // it's enemy's piece that's moving
        if (chess_board[x_d][y_d] == 0) { // the move is on an empty square
            chess_board[x_d][y_d] = chess_board[x_s][y_s];
            chess_board[x_s][y_s] = 0;
        } else { // one of my pieces is being taken
            // a one liner to take the iterator to the position of my piece in the vector
            std::vector<std::pair<char, std::pair<char, char>>>::iterator it
                = std::find(playing_pieces_mine.begin(), playing_pieces_mine.end(),
                std::pair<char, std::pair<char, char>>(std::make_pair(
                    chess_board[x_d][y_d], std::make_pair(x_d, y_d))));
            if (it != playing_pieces_mine.end()) {
                playing_pieces_mine.erase(it);
            }
        }
    }
}
