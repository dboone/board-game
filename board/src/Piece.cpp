#include "include/Piece.h"

Piece::Piece( const Position& position,
	      const std::string& symbol,
	      const std::string& color,
	      std::shared_ptr< MoveValidator > move) : position_(position), symbol_(symbol), color_(color),  moveValidator_(move)
{
}

bool Piece::isValidMove( const Position& next ) const
{
  return moveValidator_->isValid( position_, next );
}
