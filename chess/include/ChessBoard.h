#ifndef CHESS_BOARD_INCLUDED
#define CHESS_BOARD_INCLUDED

#include "include/Player.h"
#include "include/BoardGameFactory.h"
#include "include/PawnMoveValidator.h"
#include "include/RookMoveValidator.h"
#include "include/KnightMoveValidator.h"
#include "include/BishopMoveValidator.h"
#include "include/QueenMoveValidator.h"
#include "include/KingMoveValidator.h"

class ChessBoard : public Board
{
public:
  ChessBoard( size_t width, size_t height );
  
  std::vector< Piece >::iterator findPiece( const Position& position, const Player& player );
  
  void move( const Player& player );
  bool isValidMove( const Position& position, const Piece& piece ) const;
  bool isEndGame() const ;
};

#endif // CHESS_BOARD_INCLUDED
