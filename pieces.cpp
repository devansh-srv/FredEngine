#include "board.h"
#include <algorithm>
#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
uint64_t chessboard::pawnmoves(uint64_t pawn,bool isWhite,uint64_t emptysquares){
  uint64_t moves = 0;
  if(isWhite){
    moves |= (pawn<<8) & (emptysquares);
    moves |=((pawn & 0x000000000000FF00) << 16) & (emptysquares) & (emptysquares<<8);
  }
  else{
    moves |= (pawn>>8) & (emptysquares);
    moves |=((pawn & 0x00FF000000000000) >> 16) & (emptysquares) & (emptysquares>>8);
  }
  return moves;
}
uint64_t chessboard::rookmoves(uint64_t rook,uint64_t emptysquares){
  uint64_t moves = 0;
  //tbd
  return moves;
}
uint64_t chessboard::bishopmoves(uint64_t bishop,uint64_t emptysquares){
  uint64_t moves = 0;
  //tbd
  return moves;
}
uint64_t chessboard::knightmoves(uint64_t knight){
  uint64_t moves = 0;
  moves|=(knight & 0xFEFEFEFEFEFEFEFE)<<15;
  moves|=(knight & 0xFCFCFCFCFCFCFCFC)<<6;
  moves|=(knight & 0xFEFEFEFEFEFEFEFE)>>17;
  moves|=(knight & 0xFCFCFCFCFCFCFCFC)>>10;
  moves|=(knight & 0x7F7F7F7F7F7F7F7F)<<17;
  moves|=(knight & 0x3F3F3F3F3F3F3F3F)<<10;
  moves|=(knight & 0x7F7F7F7F7F7F7F7F)>>15;
  moves|=(knight & 0x3F3F3F3F3F3F3F3F)>>6;

  return moves;
}
uint64_t chessboard::queenmoves(uint64_t queen,uint64_t emptysquares){
  uint64_t moves = bishopmoves(queen,emptysquares)|rookmoves(queen,emptysquares);
  return moves;
}
uint64_t chessboard::kingmoves(uint64_t king,uint64_t emptysquares){
  uint64_t moves = 0;
  moves |= (king & 0xFEFEFEFEFEFEFEFE) << 1;
  moves |= (king & 0x7F7F7F7F7F7F7F7F) >> 1;
  moves |= king << 8;
  moves |= king >> 8;
  moves |= (king & 0xFEFEFEFEFEFEFEFE) << 9;
  moves |= (king & 0x7F7F7F7F7F7F7F7F) >> 9;
  moves |= (king & 0x7F7F7F7F7F7F7F7F) << 7;
  moves |= (king & 0xFEFEFEFEFEFEFEFE) >> 7;
  return moves & emptysquares;
}
