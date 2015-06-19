#ifndef MOVE_VALIDATOR_INCLUDED
#define MOVE_VALIDATOR_INCLUDED

#include <vector>

#include "include/Piece.h"
#include "include/Position.h"

// Interface for the different move validators
class MoveValidator
{
public:
  virtual bool isValid( const Position& curr, const Position& next ) const = 0;
};

#endif // MOVE_VALIDATOR_INCLUDED
