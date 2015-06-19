#ifndef QUEEN_MOVE_VALIDATOR_INLCUDED
#define QUEEN_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

class QueenMoveValidator : public MoveValidator
{
public:
  QueenMoveValidator()
    {
      // NO-OP
    }
  
  bool isValid( const Position& curr, const Position& next ) const
  {
    return true;
  }
};

#endif // QUEEN_MOVE_VALIDATOR_INLCUDED
