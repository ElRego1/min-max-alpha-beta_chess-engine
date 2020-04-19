#include "pieces.h"

// chess board:
// 0 - empty;
// 1 - 7 - my pieces
// 11 - 17 - enemy pieces

// return values:
// 0 - invalid move
// 1 - empty cell
// x - enemy piece and we give a score accordinglly to the importance of the piece << TODO >>
// 2 - king
// 3 - pawn
// 4 - knight
// 5 - bishop
// 6 - rook
// 7 - queen
int check_validity(char i, char j, std::vector<std::vector<char>> &chess_board) {
      if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0;
      if (chess_board[i][j] == 0) return 1; // empty cell
      if (chess_board[i][j] > 10) {
        int temp = chess_board[i][j];
        if (temp == 11) return 3; // pawn
        else if (temp == 12) return 6; // rook
        else if (temp == 13) return 4; // knight
        else if (temp == 14 || temp == 15) return 5; // bishop
        else if (temp == 16) return 7; // queen
        else if (temp == 17) return 2; // king
        else return 2;
      }
      return 0;
}

int check_validity_pawn(char i, char j, std::vector<std::vector<char>> &chess_board) {
    int temp = check_validity(i, j, chess_board);
    if (temp <= 1) return 0;
    else return temp;
}

std::vector<char> get_piece_position(char p, int d,
std::vector<std::vector<char>> &positions) {
    std::vector<char> piece_position;
    char i = -1, j = -1; // piece positions
    int contor = 0;
    for (int k = 0; k < 16; k++) {
        if (positions[k][2] == p) {
            if (contor == d) {
                i = positions[k][0];
                j = positions[k][1];
                break;
            } else {
                ++contor;
            }
      }
    }

    piece_position.push_back(i);
    piece_position.push_back(j);

    return piece_position;
}

// return vector structure: {x, y, "check_validity" return value}
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

// std::vector<char> move_piece(char x_s, char y_s, char x_d, char y_d,
//         std::vector<std::vector<char>> &positions,
//         std::vector<std::vector<char>> &e_positions,
//         std::vector<std::vector<char>> &chess_board) {
//     if (chess_board[x_s][y_s] == 0) {
//         std::cout << "#probleme\n";
//         return NULL;
//     }
//
//     char piece_type = chess_board[x_s][y_s];
//     if (piece_type < 10) { //it's my piece
//     std::vector<char> pos_rmv;
//         if (chess_board[x_d][y_d] != 0) { // taking enemy's piece
//             pos_rmv.push_back(x_d);
//             pos_rmv.push_back(y_d);
//             pos_rmv.push_back(chess_board[x_d][y_d]);
//             auto it = std::find(e_positions.begin(), e_positions.end(), pos_rmv);
//             e_positions.erase(it);
//         }
//         chess_board[x_d][y_d] = chess_board[x_s][y_s];
//         chess_board[x_s][y_s] = 0;
//         std::vector<char> pos;
//         pos.push_back(x_s);
//         pos.push_back(y_s);
//         pos.push_back(piece_type);
//         auto it = std::find(positions.begin(), positions.end(), pos);
//         positions.erase(it);
//         pos.erase(it);
//         pos.push_back(x_d);
//         pos.push_back(y_d);
//         pos.push_back(piece_type);
//         positions.push_back(pos);
//         // TODO
//         // make the special move the rook and the king
//         return pos_rmv;
//     } else { // it's enemy's piece that's moving
//         std::vector<char> pos_rmv;
//         if (chess_board[x_d][y_d] != 0) { // taking my piece
//             pos_rmv.push_back(x_d);
//             pos_rmv.push_back(y_d);
//             pos_rmv.push_back(chess_board[x_d][y_d]);
//             auto it = std::find(positions.begin(), positions.end(), pos);
//             positions.erase(it);
//         }
//         chess_board[x_d][y_d] = chess_board[x_s][y_s];
//         chess_board[x_s][y_s] = 0;
//         std::vector<char> pos;
//         pos.push_back(x_s);
//         pos.push_back(y_s);
//         pos.push_back(piece_type);
//         auto it = std::find(e_positions.begin(), e_positions.end(), pos);
//         e_positions.erase(it);
//         pos.erase(it);
//         pos.push_back(x_d);
//         pos.push_back(y_d);
//         pos.push_back(piece_type);
//         e_positions.push_back(pos);
//         return pos_rmv;
//     }
// }


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
    if (temp >= 2) break; // it's an enemy piece and we can not jump over it
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
      move.push_back(temp);
      possible_moves.push_back(move);
      if (temp >= 2) break;
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
      move.push_back(temp);
      possible_moves.push_back(move);
      if (temp >= 2) break;
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
      move.push_back(temp);
      possible_moves.push_back(move);
      if (temp >= 2) break;
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
      move.push_back(temp);
      possible_moves.push_back(move);
      if (temp >= 2) break;
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

// ------------------------------------------ Ollie's diagonal moves 8) --------------------------------

void right_diag_up(char i, char j, std::vector<std::vector<char>> &possible_moves, std::vector<std::vector<char>> &chess_board) {
  while (true) {
    int temp = check_validity(i + 1, j + 1, chess_board); // 1 - empty ; 2 - enemy
    if (temp == 0) break;
    std::vector<char> move;
    move.push_back(i + 1);
    move.push_back(j + 1);
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp >= 2) break;
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
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp >= 2) break;
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
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp >= 2) break;
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
    move.push_back(temp);
    possible_moves.push_back(move);
    if (temp >= 2) break;
    --i;
    --j;
  }
}
