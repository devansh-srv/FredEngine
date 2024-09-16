#include "board.h"
#include "board.cpp"
#include "pieces.cpp"
#include <cstdint>
using namespace std;
int main (int argc, char *argv[]) {
  chessboard cb;
  cb.printBoard();
  cout<<endl;
  uint64_t emptysquares = ~(cb.blackKing|cb.whiteKing|cb.blackPawns|cb.whitePawns|cb.blackQueen|cb.whiteQueen|cb.blackRooks|cb.whiteRooks|cb.blackKnights|cb.whiteKnights|cb.blackBishops|cb.whiteBishops);
  // cout<<emptysquares<<endl;
  cout<<endl;
  uint64_t pawnMoves = cb.pawnmoves(cb.blackPawns, false, emptysquares);
  cb.printBitBoard(pawnMoves);
  cout<<endl;
  uint64_t knightMoves = cb.knightmoves(cb.whiteKnights);
  cb.printBitBoard(knightMoves);
  cout<<endl;
  uint64_t kingMoves = cb.kingmoves(cb.whiteKing,emptysquares);
  cout<<kingMoves<<endl;
  cb.printBitBoard(kingMoves);
  cout<<endl;
  return 0;
}
