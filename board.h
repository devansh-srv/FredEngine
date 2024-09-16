#ifndef BOARD_H
#define BOARD_H
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
class chessboard{
  void fillboard(char board[8][8],uint64_t bitboard,char piece);
public:
  uint64_t whitePawns;
  uint64_t whiteRooks;
  uint64_t whiteKnights;
  uint64_t whiteBishops;
  uint64_t whiteQueen;
  uint64_t whiteKing;

  uint64_t blackPawns;
  uint64_t blackRooks;
  uint64_t blackKnights;
  uint64_t blackBishops;
  uint64_t blackQueen;
  uint64_t blackKing;
  enum Piece{
    nWhite,
    nBlack,
    nPawn,
    nKnight,
    nBishop,
    nRook,
    nQueen,
    nKing
  };
  chessboard();
  void printBoard();
  uint64_t pawnmoves(uint64_t pawns,bool isWhite,uint64_t emptysquares);
  uint64_t rookmoves(uint64_t rooks,uint64_t emptysquares);
  uint64_t knightmoves(uint64_t knights);
  uint64_t bishopmoves(uint64_t bishops,uint64_t emptysquares);
  uint64_t queenmoves(uint64_t queen,uint64_t emptysquares);
  uint64_t kingmoves(uint64_t king,uint64_t emptysquares);
  // void printBitBoard(uint64_t bitboard,char piece);
  void printBitBoard(uint64_t bitboard);
};
#endif
