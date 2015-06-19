#ifndef KING_MOVE_VALIDATOR_INLCUDED
#define KING_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

class KingMoveValidator : public MoveValidator
{
public:
  KingMoveValidator()
    {
    }

  bool isValid( const Position& curr, const Position& next ) const
  {
    return true;
  }
};

#endif // KING_MOVE_VALIDATOR_INLCUDED
