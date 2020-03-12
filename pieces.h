/*

0 - empty sapce
1 - pawns
2 - the rook
3 - the knight
4 - the black bishop
5 - the white bishop
6 - the queen
7 - the king

*/

#ifndef PIECES_H
#define PIECES_H

void get_piece_directions(char p);
void move_piece(char p, char x, char y, int d);



#endif // PIECES_H