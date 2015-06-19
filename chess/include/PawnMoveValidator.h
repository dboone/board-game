#ifndef PAWN_MOVE_VALIDATOR_INLCUDED
#define PAWN_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

// A pawn can move in one of three ways:
// (1) Forward one
// (2) Forward two -- only from the home line
// (3) Left or right one -- only to capture
class PawnMoveValidator : public MoveValidator
{
public:
  PawnMoveValidator()
    {
    }

  // TODO - how do I know which direction the piece is moving? pawns can't move backwards.
  // TODO - how do I know if the pawn is attacking? vistor to board?
  bool isValid( const Position& curr, const Position& next ) const
  {
    // not moving is not a valid move
    if ( curr == next )
      return false;
    
    // white moving forward one
    if ( curr.getFile() == next.getFile() && next.getRank() - curr.getRank() == 1 )
      return true;
    
    // white moving forward two
    if ( curr.getFile() == next.getFile() && next.getRank() - curr.getRank() == 2 && curr.getRank() == 2 )
      return true;
    
    // black moving forward one
    if ( curr.getFile() == next.getFile() && next.getRank() - curr.getRank() == 1 )
      return true;
    
    // black moving forward two
    if ( curr.getFile() == next.getFile() && next.getRank() - curr.getRank() == -2 && curr.getRank() == 7 )
      return true;
    
    return false;
  }
};

#endif // PAWN_MOVE_VALIDATOR_INLCUDED
