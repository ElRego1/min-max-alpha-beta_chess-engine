#include "minimax.h"

// ---------------------------------- MINIMAX --------------------------------

int alphabeta_maxi(int depth, int alpha, int beta, Game &g) {
  if (depth == 0) {
    return evaluate(g.m_board, g.m_pieces, g.e_board, g.e_pieces);
  }
  std::vector<std::vector<char>> all_moves = get_moves_m(g);
  // {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  for (auto &move : all_moves) {
    int score;
    // holds info to undo the move later: {piece_taken}
    std::vector<char> info = g.apply_move_m(move);
    
    if (g.is_check_m) {
      score = LOW - 1;
    } else {
      score = alphabeta_mini(depth - 1, alpha, beta, g);
    }

    // partea de alpha-beta
    if (score >= beta) {
      return beta;
    }
    if (score > alpha) {
      alpha = score;
    }

    g.undo_move_m(info, move);
  }
  return alpha;
}


int alphabeta_mini(int depth, int alpha, int beta, Game &g){
  if (depth == 0) {
    return -evaluate(g.e_board, g.e_pieces, g.m_board, g.m_pieces);
  }
  std::vector<std::vector<char>> all_moves = get_moves_e(g);
  // {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  for (auto &move : all_moves) {
    g.apply_move_e(move);

    int score;
    
    if (g.is_check_e) {
      score = HIGH + 1; // not a good move for the mini part as it enters chess
    }else {
      score = alphabeta_maxi(depth - 1, alpha, beta, g);
    }

    // partea de alpha-beta
    if (score <= alpha) {
      return alpha;
    }
    if (score < beta) {
      beta = score;
    }
    // TODO
    // g.undo_move_e(move);
  }
  return beta;
}

// ---------------------------------- EVALUATE --------------------------------

int evaluate(std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces) {

  return 0;
}

// --------------------------------- GET_MOVES_X ------------------------------

// return vector structure: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
std::vector<std::vector<char>> get_moves_m(Game &g) {
  std::vector<std::vector<char>> moves;
  return get_moves(g.m_pieces, g.m_board);
}

// return vector structure: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
std::vector<std::vector<char>> get_moves_e(Game &g) {
  std::vector<std::vector<char>> moves;
  return get_moves(g.e_pieces, g.e_board);
}

// return vector structure: {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
// priority code:
// 1 - an empty cell
// 2 - an enemy piece
// 3 - chess for the enemy << TODO >>
std::vector<std::vector<char>> get_moves(std::vector<std::vector<char>> &pieces, std::vector<std::vector<char>> &board) {
  std::vector<std::vector<char>> moves;
  // structure for piece: {x, y, piece_type}
  for (std::vector<char> piece : pieces) {
    if (piece[0] < 0 || piece[1] < 0) {
      continue;
    }
    // {x, y, return code from "check_validity"}
    std::vector<std::vector<char>> temp = get_piece_directions(piece[0], piece[1], board);
    for (auto &x : temp) {
      std::vector<char> v;
      v.push_back(piece[0]); // src_x
      v.push_back(piece[1]); // src_y
      v.push_back(x[0]);     // dst_x
      v.push_back(x[1]);     // dst_y
      v.push_back(piece[2]); // piece_type
      v.push_back(x[2]);     // priority_code

      moves.push_back(v);
    }
  }
  return moves;
}