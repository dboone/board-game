#ifndef BISHOP_MOVE_VALIDATOR_INLCUDED
#define BISHOP_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

class BishopMoveValidator : public MoveValidator
{
public:
  BishopMoveValidator()
    {
    }

  bool isValid( const Position& curr, const Position& next ) const
  {
    return true;
  }
};

#endif // BISHOP_MOVE_VALIDATOR_INLCUDED
