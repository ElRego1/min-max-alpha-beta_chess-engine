#include "game.h"
#include "init_game.h"

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