#ifndef CONSTANTS_H
#define CONSTANTS_H

#define NO_COLOR -1
#define WHITE 0
#define BLACK 1

#define PIECE_TAKEN -1

#define BOX_SQUARES 64
#define BOX_LENGTH 8
#define NO_PIECES 16
#define NO_COORD 2

#define EMPTY_CELL 0

#define PAWN_M 1
#define ROOK_M 2
#define KNIGHT_M 3
#define BLACK_BISHOP_M 4
#define WHITE_BISHOP_M 5
#define QUEEN_M 6
#define KING_M 7

#define PAWN_E 11
#define ROOK_E 12
#define KNIGHT_E 13
#define BLACK_BISHOP_E 14
#define WHITE_BISHOP_E 15
#define QUEEN_E 16
#define KING_E 17

// minimax
#define LOW -10000
#define HIGH 10000

#define PRIORITY_EMPTY_CELL 1
#define PRIORITY_PAWN 3
#define PRIORITY_ROOK 6
#define PRIORITY_KNIGHT 4
#define PRIORITY_WHITE_BISHOP 5
#define PRIORITY_BLACK_BISHOP 5
#define PRIORITY_QUEEN 7
#define PRIORITY_KING 2

#define SCORE_PAWN 100
#define SCORE_ROOK 500
#define SCORE_KNIGHT 300
#define SCORE_WHITE_BISHOP 300
#define SCORE_BLACK_BISHOP 300
#define SCORE_QUEEN 900
#define SCORE_KING 0 // schould be on the board

#define SCORE_KING_SAFE 150
#define SCORE_KING_THREATENED -150 

#define SCORE_INV_PRO 250 // score invers proportional

#endif // CONSTANTS_H
