#include "minimax.h"

int alphabeta_maxi(int depth, int alpha, int beta, Game &g) {
  if (depth == 0 || g.game_over()) {
    return evaluate();
  }

  std::vector<std::vector<char>> all_moves = get_moves_m(g);

  for (auto &move : all_moves) {
    g.apply_move(move);

    int score = alphabeta_mini(depth - 1, alpha, beta, g);

    if (score >= beta) {
      return beta;
    }

    if (score > alpha) {
      alpha = score;
    }

    g.undo_move(move);
  }
  return alpha;
}


int alphabeta_mini(int depth, int alpha, int beta, Game &g){
  if (depth == 0 || g.game_over()) {
    return -evaluate();
  }

  std::vector<std::vector<char>> all_moves = get_moves_e(g);

  for (auto &move : all_moves) {
    g.apply_move(move);

    int score = alphabeta_maxi(depth - 1, alpha, beta, g);

    if (score <= alpha) {
      return alpha;
    }

    if (score < beta) {
      beta = score;
    }

    g.undo_move(move);
  }
  return beta;
}