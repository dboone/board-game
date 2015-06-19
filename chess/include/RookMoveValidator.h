#ifndef ROOK_MOVE_VALIDATOR_INLCUDED
#define ROOK_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

class RookMoveValidator : public MoveValidator
{
public:
  RookMoveValidator()
    {
    }
  
  // rooks can move in straight lines
  bool isValid( const Position& curr, const Position& next ) const
  {
    // implicit
    //if ( curr == next )
    //	return false;
    
    // change in rank ONLY
    if ( curr.getFile() == next.getFile() && curr.getRank() != next.getRank() )
      return true;
    
    // change in file ONLY
    if ( curr.getRank() == next.getRank() && curr.getFile() != next.getFile() )
      return true;
    
    return false;
  }
};

#endif // ROOK_MOVE_VALIDATOR_INLCUDED
