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

int check_validity(int i, int j);
std::vector<std::vector<char>> get_piece_directions(char p);
void move_piece(char p, char x, char y, int d);



#endif // PIECES_H
