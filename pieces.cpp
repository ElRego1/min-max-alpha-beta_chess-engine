#include "pieces.h"

// chess board:
// 0 - empty;
// 1 - 7 - my pieces
// 11 - 17 - enemy pieces

int check_validity(char i, char j, std::vector<std::vector<char>> &chess_board) {
      if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0;
      if (chess_board[i][j] == 0) return 1;
      if (chess_board[i][j] > 10) return 2;
      return 0;
}

int check_validity_pawn(char i, char j, std::vector<std::vector<char>> &chess_board) {
    if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0;
    if (chess_board[i][j]!=0 && chess_board[i][j] > 10) return 2;
    return 0;
}

std::vector<char> get_piece_position(char p, int d,
std::vector<std::vector<char>> &positions) {
    std::vector<char> piece_position;
    char i, j; // piece positions
    switch (p) {
        case 1: // pawn
            i = positions[d][0];
            j = positions[d][1];
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
            j = positions[12 + d][1];
            break;

        case 5: // white bishop
            i = positions[13 + d][0];
            j = positions[13 + d][1];
            break;

        case 6: // queen
            i = positions[14 + d][0];
            j = positions[14 + d][1];
            break;

        case 7: // king
            i = positions[15 + d][0];
            j = positions[15 + d][1];
            break;
        default:
            break;
    }
    piece_position.push_back(i);
    piece_position.push_back(j);

    return piece_position;
}

std::vector<std::vector<char>> get_piece_directions(char i, char j, std::vector<std::vector<char>> &chess_board) {
    std::vector<std::vector<char>> possible_moves;
    char piece_type = chess_board[i][j];
    switch (piece_type) {
        case 1: {// pawn
            if (i == 1 && chess_board[2][j] == 0) { // pt cand pionul se misca 2 patratele
                check_move(i, j, 2, 0, possible_moves, chess_board);
            }

            check_move(i, j, 1, 0, possible_moves, chess_board);

            int temp = check_validity_pawn(i + 1, j - 1, chess_board); // adversar pe diagonala stanga
            if (temp) {
                std::vector<char> move;
                move.push_back(i + 1);
                move.push_back(j - 1);
                move.push_back(temp);
                possible_moves.push_back(move);
            }
            temp = check_validity_pawn(i + 1, j + 1, chess_board); // adversar pe diagonala dreapta
            if (temp) {
                std::vector<char> move;
                move.push_back(i + 1);
                move.push_back(j + 1);
                move.push_back(temp);
                possible_moves.push_back(move);
            }
            break;
          }

        case 2: // rook
            check_move_up(i, j, possible_moves, chess_board);
            check_move_down(i, j, possible_moves, chess_board);
            check_move_left(i, j, possible_moves, chess_board);
            check_move_right(i, j, possible_moves, chess_board);
            break;

        case 3: // knight
            // front moves
            check_move(i, j, 2, -1, possible_moves, chess_board);
            check_move(i, j, 2, 1, possible_moves, chess_board);
            check_move(i, j, 1, -2, possible_moves, chess_board);
            check_move(i, j, 1, 2, possible_moves, chess_board);

            // back moves
            check_move(i, j, -2, -1, possible_moves, chess_board);
            check_move(i, j, -2, 1, possible_moves, chess_board);
            check_move(i, j, -1, -2, possible_moves, chess_board);
            check_move(i, j, -1, 2, possible_moves, chess_board);
            break;

        case 4: // black bishop
        case 5: // white bishop
            right_diag_up(i, j, possible_moves, chess_board);
            left_diag_up(i, j, possible_moves, chess_board);
            right_diag_down(i, j, possible_moves, chess_board);
            left_diag_down(i, j, possible_moves, chess_board);
            break;

        case 6: // queen
            check_move_up(i, j, possible_moves, chess_board);
            check_move_down(i, j, possible_moves, chess_board);
            check_move_left(i, j, possible_moves, chess_board);
            check_move_right(i, j, possible_moves, chess_board);
            right_diag_up(i, j, possible_moves, chess_board);
            left_diag_up(i, j, possible_moves, chess_board);
            right_diag_down(i, j, possible_moves, chess_board);
            left_diag_down(i, j, possible_moves, chess_board);
            break;

        case 7: // king
            check_move(i, j, 1, 0, possible_moves, chess_board);
            check_move(i, j, -1, 0, possible_moves, chess_board);
            check_move(i, j, 0, 1, possible_moves, chess_board);
            check_move(i, j, 0, -1, possible_moves, chess_board);
            check_move(i, j, 1, 1, possible_moves, chess_board);
            check_move(i, j, 1, -1, possible_moves, chess_board);
            check_move(i, j, -1, 1, possible_moves, chess_board);
            check_move(i, j, -1, -1, possible_moves, chess_board);
            break;

        default:
            break;
    }

   return possible_moves;
}

void move_piece(char x_s, char y_s, char x_d, char y_d,
        std::vector<std::vector<char>> &chess_board,
        std::vector<std::pair<char, std::pair<char, char>>> &playing_pieces_mine) {
    if (chess_board[x_s][y_s] == 0) {
        std::cout << "#probleme\n";
    }

    if (chess_board[x_s][y_s] < 10) { //it's my piece
        playing_pieces_mine[0].second.first = x_d;
        playing_pieces_mine[0].second.second = y_d;
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

// --------------------------------------------- Robert's attemp --------------------------------

// here we get the moves for the bishop
void rook_moves(char &i, char &j,
std::vector<std::vector<char>> &possible_moves,
std::vector<std::vector<char>> &chess_board) {
  get_direct_moves(i, j, up, possible_moves, chess_board);
  get_direct_moves(i, j, dw, possible_moves, chess_board);
  get_direct_moves(i, j, rg, possible_moves, chess_board);
  get_direct_moves(i, j, lf, possible_moves, chess_board);
}

void bishop_moves(char &i, char &j,
std::vector<std::vector<char>> &possible_moves,
std::vector<std::vector<char>> &chess_board) {
  get_direct_moves(i, j, ur, possible_moves, chess_board);
  get_direct_moves(i, j, ul, possible_moves, chess_board);
  get_direct_moves(i, j, dr, possible_moves, chess_board);
  get_direct_moves(i, j, dl, possible_moves, chess_board);
}

// get directional moves
// pair d<x, y> gives the direction in whitch to search for moves
// good for the following pieces:
// -rook
// -bishop
// -queen
// example: (1, 0) = goes forward; (-1, -1) = goes on the down left diagonal
void get_direct_moves(char i, char j, std::pair<char, char> &d,
std::vector<std::vector<char>> &possible_moves,
std::vector<std::vector<char>> &chess_board) {
  char x = d.first;
  char y = d.second;
  while (true) {
    int temp = check_validity(i + x, j + y, chess_board);
    if (temp == 0) break; // our piece and is an invalid move
    std::vector<char> move;
    move.push_back(i + x);
    move.push_back(j + y);
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp == 2) break; // it's an enemy piece and we can not jump over it
    i += x;
    j += y;
  }
}

// --------------------------------------------- Teo's moves --------------------------------

void check_move_up(char i, char j, std::vector<std::vector<char>> &possible_moves,
  std::vector<std::vector<char>> &chess_board) {
    while (true) {
      int temp = check_validity(i + 1, j, chess_board);
      if (temp == 0) break;
      std::vector<char> move;
      move.push_back(i + 1);
      move.push_back(j);
      possible_moves.push_back(move);
      if (temp == 2) break;
      ++i;
    }
}

void check_move_down(char i, char j, std::vector<std::vector<char>> &possible_moves,
  std::vector<std::vector<char>> &chess_board) {
    while (true) {
      int temp = check_validity(i - 1, j, chess_board);
      if (temp == 0) break;
      std::vector<char> move;
      move.push_back(i - 1);
      move.push_back(j);
      possible_moves.push_back(move);
      if (temp == 2) break;
      --i;
    }
}

void check_move_left(char i, char j, std::vector<std::vector<char>> &possible_moves,
  std::vector<std::vector<char>> &chess_board) {
    while (true) {
      int temp = check_validity(i, j - 1, chess_board);
      if (temp == 0) break;
      std::vector<char> move;
      move.push_back(i);
      move.push_back(j - 1);
      possible_moves.push_back(move);
      if (temp == 2) break;
      --j;
    }

}

void check_move_right(char i, char j, std::vector<std::vector<char>> &possible_moves,
  std::vector<std::vector<char>> &chess_board) {
    while (true) {
      int temp = check_validity(i, j + 1, chess_board);
      if (temp == 0) break;
      std::vector<char> move;
      move.push_back(i);
      move.push_back(j + 1);
      possible_moves.push_back(move);
      if (temp == 2) break;
      ++j;
    }
}

void check_move(char i, char j, int i_depl, int j_depl, std::vector<std::vector<char>> &possible_moves,
  std::vector<std::vector<char>> &chess_board) {
    int temp = check_validity(i + i_depl, j + j_depl, chess_board);
    if (temp) {
      std::vector<char> move;
      move.push_back(i + i_depl);
      move.push_back(j + j_depl);
      move.push_back(temp);
      possible_moves.push_back(move);
    }
  }

// --------------------------------------------- diagonal moves --------------------------------

void right_diag_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board) {
  while (true) {
    int temp = check_validity(i + 1, j + 1, chess_board); // 1 - empty ; 2 - enemy
    if (temp == 0) break;
    std::vector<char> move;
    move.push_back(i + 1);
    move.push_back(j + 1);
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp == 2) break;
    ++i;
    ++j;
  }
}

void left_diag_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board) {
  while (true) {
    int temp = check_validity(i + 1, j - 1, chess_board);
    if (temp == 0) break;
    std::vector<char> move;
    move.push_back(i + 1);
    move.push_back(j - 1);
    possible_moves.push_back(move);
    if (temp == 2) break;
    ++i;
    --j;
  }
}

void right_diag_down(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board) {
  while (true) {
    int temp = check_validity(i - 1, j + 1, chess_board);
    if (temp == 0) break;
    std::vector<char> move;
    move.push_back(i - 1);
    move.push_back(j + 1);
    possible_moves.push_back(move);
    if (temp == 2) break;
    --i;
    ++j;
  }
}

void left_diag_down(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board) {
  while (true) {
    int temp = check_validity(i - 1, j - 1, chess_board);
    if (temp == 0) break;
    std::vector<char> move;
    move.push_back(i - 1);
    move.push_back(j - 1);
    possible_moves.push_back(move);
    if (temp == 2) break;
    --i;
    --j;
  }
}
