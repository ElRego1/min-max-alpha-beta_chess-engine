#include "minimax.h"

// ---------------------------------- MINIMAX --------------------------------

int alphabeta_maxi(int depth, int alpha, int beta, Game &g) {
  std::cout<<"# am ajuns in alphabeta_maxi" << "\n";
  if (depth == 0) {
    return evaluate(g.m_board, g.m_pieces, g.e_board, g.e_pieces);
  }
  // {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  std::vector<std::vector<char>> all_moves = get_moves_m(g);
  std::sort(all_moves.begin(), all_moves.end(), order_moves_by_priority);
  for (auto &move : all_moves) {
    int score;
    // holds info to undo the move later: {piece_taken}
    std::vector<char> info = g.apply_move_m(move);
    std::cout << "# MAXI COUT 1" << std::endl;
    std::cout<< "#"<< "\n";

	for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.m_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.m_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  std::cout << std::endl;

	std::cout<< "#"<< "\n";
  for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.e_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.e_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }

    if (g.is_check_m()) {
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
    std::cout << "# MAXI COUT 2" << std::endl;
    std::cout<< "#"<< "\n";

	for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.m_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.m_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  std::cout << std::endl;

	std::cout<< "#"<< "\n";
  for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.e_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.e_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  }
  return alpha;
}


int alphabeta_mini(int depth, int alpha, int beta, Game &g){
  std::cout<<"# am ajuns in alphabeta_mini" << "\n";
  if (depth == 0) {
    return -evaluate(g.e_board, g.e_pieces, g.m_board, g.m_pieces);
  }
  std::cout<<"# am trecut de evaluate" << "\n";
  // {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
  std::vector<std::vector<char>> all_moves = get_moves_e(g);
  std::sort(all_moves.begin(), all_moves.end(), order_moves_by_priority);
  std::cout<<"# am trecut de sort get_moves_e" << "\n";
  for (auto &move : all_moves) {
    std::vector<char> info = g.apply_move_e(move);
    std::cout << "# MINI COUT 3" << std::endl;
std::cout<< "#"<< "\n";

	for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.m_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.m_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  std::cout << std::endl;

	std::cout<< "#"<< "\n";
  for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.e_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.e_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }

    // holds info to undo the move later: {piece_taken}
    int score;
    std::cout<<"# am trecut de apply_moves_e" << "\n";

    if (g.is_check_e()) {
      std::cout<<"# am intrat in check" << "\n";
      score = HIGH + 1; // not a good move for the mini part as it enters chess
    }else {
      std::cout<<"# am intrat in check" << "\n";
      score = alphabeta_maxi(depth - 1, alpha, beta, g);
    }
    std::cout<<"# am trecut de alphabeta_maxi" << "\n";

    // partea de alpha-beta
    if (score <= alpha) {
      return alpha;
    }
    if (score < beta) {
      beta = score;
    }

    g.undo_move_e(info, move);
    std::cout << "# MINI COUT 4" << std::endl;
    std::cout<< "#"<< "\n";

	for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.m_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.m_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  std::cout << std::endl;

	std::cout<< "#"<< "\n";
  for (int i = 0; i < 8; ++i) {
    std::cout << "# ";
    for (int j = 0; j < 8; ++j) {
      std::cout << std::setw(3) << (int)g.e_board[i][j]<< " ";
    }
    std::cout << std::endl;
  }

  for (auto d : g.e_pieces) {
	  std::cout <<"#" << (int) d[0] << " " << (int) d[1] << " "<< (int) d[2] << std::endl;
  }
  }
  return beta;
}

// ---------------------------------- EVALUATE --------------------------------

int evaluate(std::vector<std::vector<char>> &p_board,std::vector<std::vector<char>> &p_pieces,
std::vector<std::vector<char>> &h_board, std::vector<std::vector<char>> &h_pieces) {
  int score_p = 0;
  int score_h = 0;

  // sum of pieces in the game
  // my pieces
  for (auto &v : p_pieces) {
    if (v[0] != PIECE_TAKEN && v[1] != PIECE_TAKEN) {
      score_p += get_score(v[2]);
      // check if I am in check
      if (v[2] == KING_M) {
        if (check_check(v[0], v[1], p_board) == 0) {
          score_p += SCORE_KING_SAFE;
        } else {
          score_p += SCORE_KING_THREATENED;
        }
      }
    }
  }
  // enemy's pieces
  for (auto &v : h_pieces) {
    if (v[0] != PIECE_TAKEN && v[1] != PIECE_TAKEN) {
      score_h += get_score(v[2]);
      // check if the enemy is in check
      if (v[2] == KING_M) {
        if (check_check(v[0], v[1], h_board) == 0) {
          score_h += SCORE_KING_SAFE;
        } else {
          score_h += SCORE_KING_THREATENED;
        }
      }
    }
  }

  // pieces that i can attack
  for (auto &v : p_pieces) {
    if (v[0] != PIECE_TAKEN && v[1] != PIECE_TAKEN) {
      // a vector of {x, y, piece type}
      std::vector<std::vector<char>> victims = check_attack(v[0], v[1], p_board);
      for (auto &victim : victims) {
        int victim_piece = victim[2] - 10;
        score_p += get_score(victim_piece) * (SCORE_INV_PRO / v[2]);
      }
    }
  }

  // pieces that are in danger
  for (auto &v : p_pieces) {
    if (v[0] != PIECE_TAKEN && v[1] != PIECE_TAKEN) {
      // a vector of {x, y, piece type}
      std::vector<std::vector<char>> perpetrators = check_attackers(v[0], v[1], p_board);
      for (auto &perpetrator : perpetrators) {
        int perpetrator_piece = perpetrator[2] - 10;
        score_p -= get_score(v[2]) * (SCORE_INV_PRO / perpetrator_piece);
      }
    }
  }

  return (score_p - score_h);
}

int get_score(const int &piece_type) {
  switch (piece_type) {
    case PAWN_M:
      return SCORE_PAWN;
    case ROOK_M:
      return SCORE_ROOK;
    case KNIGHT_M:
      return SCORE_KNIGHT;
    case WHITE_BISHOP_M:
      return SCORE_WHITE_BISHOP;
    case BLACK_BISHOP_M:
      return SCORE_BLACK_BISHOP;
    case QUEEN_M:
      return SCORE_QUEEN;
    case KING_M:
      return SCORE_KING;
    default:
      std::cout << "#ERROR: Found a piece_type that did not mach anything in \"get_score\"" << std::endl;
      return 0;
  }
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

// {src_x, src_y, dst_x, dst_y, piece_type, priority_code}
bool order_moves_by_priority(const std::vector<char> &a, const std::vector<char> &b) {
  if (a[5] != b[5]) {
    return a[5] > b[5]; // order descending by the priority of the piece that can be taken
  } else {
    return a[4] < b[4]; // if priority is equal, order ascending by the type of piece doing the attack
  }
}
