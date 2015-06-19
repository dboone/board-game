#ifndef KNIGHT_MOVE_VALIDATOR_INLCUDED
#define KNIGHT_MOVE_VALIDATOR_INLCUDED

#include "include/MoveValidator.h"

class KnightMoveValidator : public MoveValidator
{
public:
	KnightMoveValidator()
	{
		// NO-OP
	}

	bool isValid( const Position& curr, const Position& next ) const
	{
		return true;
	}
};

#endif // KNIGHT_MOVE_VALIDATOR_INLCUDED
