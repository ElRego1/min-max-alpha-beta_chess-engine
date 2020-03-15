#include <bits/stdc++.h>
#include "communications.h"
#include "init_game.h"
#include "pieces.h"
#include "matrix_transformation.h"

int check_validity(int i, int j) {
  if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0;
  return 1;
}

std::vector<std::vector<char>> get_piece_directions(char p, int d) {
  std::vector<std::vector<char>> possible_moves;
  int i, j; // piece positions;
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

}

void move_piece(char p, char x, char y, int d) {

}
