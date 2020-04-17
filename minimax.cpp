#include "minimax.h"

// ---------------------------------- MINIMAX --------------------------------

int alphabeta_maxi(int depth, int alpha, int beta, Game &g) {
  if (depth == 0 || g.game_over()) {
    return evaluate();
  }

  std::vector<std::vector<char>> all_moves = get_moves_m(g);

  for (auto &move : all_moves) {
    int score;

    g.apply_move_m(move);
    
    if (g.is_check_m) {
      score = LOW - 1;
    } else {
      score = alphabeta_mini(depth - 1, alpha, beta, g);
    }

    if (score >= beta) {
      return beta;
    }

    if (score > alpha) {
      alpha = score;
    }

    g.undo_move_m(move);
  }
  return alpha;
}


int alphabeta_mini(int depth, int alpha, int beta, Game &g){
  if (depth == 0 || g.game_over()) {
    return -evaluate();
  }

  std::vector<std::vector<char>> all_moves = get_moves_e(g);

  for (auto &move : all_moves) {
    g.apply_move_e(move);

    int score;
    
    if (g.is_check_e) {
      score = HIGH + 1;
    }else {
      score = alphabeta_maxi(depth - 1, alpha, beta, g);
    }
    if (score <= alpha) {
      return alpha;
    }

    if (score < beta) {
      beta = score;
    }

    g.undo_move_e(move);
  }
  return beta;
}

// --------------------------------- GET_MOVES_X -----------------------------

std::vector<std::vector<char>> get_moves_m(Game &g) {
  std::vector<std::vector<char>> moves;
  for (std::vector<char> piece : g.m_pieces) {
    if (piece[0] < 0 || piece[1] < 0) {
      continue;
    }
    std::vector<std::vector<char>> temp = get_piece_directions(piece[0], piece[1], g.m_board);
    moves.insert(moves.end(), temp.begin(), temp.end());
  }
  return moves;
}

std::vector<std::vector<char>> get_moves_e(Game &g) {
  std::vector<std::vector<char>> moves;
  for (std::vector<char> piece : g.e_pieces) {
    if (piece[0] < 0 || piece[1] < 0) {
      continue;
    }
    std::vector<std::vector<char>> temp = get_piece_directions(piece[0], piece[1], g.e_board);
    moves.insert(moves.end(), temp.begin(), temp.end());
  }
  return moves;
}