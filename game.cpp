#include "game.h"
#include "init_game.h"
#include "pieces.h"

Game::Game(char wb) {
  make_print_board_matrix(*this, wb);

  // init my color, board and vector of pieces
  m_color = wb;
  m_board = get_initial_board_matrix(m_color);
	m_pieces = get_initial_positions(m_color);

  // init enemy's color, board and vector of pieces
  if (wb == 0) { // if we are white
    e_color = 1; // enemy is black
  } else {       // if we are black
    e_color = 0; // enemy is white
  }
  e_board = get_initial_board_matrix(e_color);
  e_pieces = get_initial_positions(e_color);
}

void Game::remake_print_board(char wb) {
  make_print_board_matrix(*this, wb);
}

bool Game::is_check_m() {
  char x, y;
  for (auto &v : m_pieces) {
    if (v[2] == 7) {  // my king position
      x = v[0];
      y = v[1];
      break;
    }
  }

  int valid = 0;
  valid += check_check(x, y, ur, m_board);
  if (valid != 0) return true; // sah
  return false; //safe
}

bool Game::is_check_e() {
  char x, y;
  for (auto &v : e_pieces) {
    if (v[2] == 7) {  // my king position
      x = v[0];
      y = v[1];
      break;
    }
  }

  int valid = 0;
  valid += check_check(x, y, ur, e_board);
  if (valid != 0) return true; // sah
  return false; //safe
}

// 0 - rege safe
// 1 - rege atacat
int check_check(char i, char j, std::pair<char, char> &d,
std::vector<std::vector<char>> &chess_board) {
  char x = d.first;
  char y = d.second;
  //todo pion diagonala o patratica numai diag sus
  //todo cal orice directie in l
  while (true) {
    int temp = check_check_validity(i + x, j + y, chess_board);
    if (temp == 0) return 0; // a iesit din tabla liber drum
    if (temp == 1) return 0; // a dat de piesa mea
    if (temp == 2) {  // a dat de inamic
      int cod_piesa = chess_board[i + x][j + y];
      if ((d == ur || d == ul || d == dr || d == dl) && (cod_piesa == 14 || cod_piesa == 15 || cod_piesa == 16)) return 1; // diagonala si nebuni si regina
      if ((d == up || d == dw || d == rg || d == lf) && (cod_piesa == 12 || cod_piesa == 16)) return 1; // tura care e in lini si regina
      return 0;
    }
    i += x;
    j += y;
  }
  return 0;
}

// 0 - iesit din tabla
// 1 - piesa mea
// 2 - inamic
// 3 - casuta libera
int check_check_validity(char i, char j, std::vector<std::vector<char>> &chess_board) {
      if (i < 0 || i >= BOX_LENGTH || j < 0 || j >= BOX_LENGTH) return 0; // iesit tabla
      if (chess_board[i][j] > 10) return 2; // inamic
      if (chess_board[i][j] > 0) return 1; // piesa mea
      return 3;
}
