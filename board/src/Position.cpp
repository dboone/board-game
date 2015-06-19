#include "include/Position.h"

bool Position::operator==( const Position& right ) const
{
  return this->getFile() == right.getFile() && this->getRank() == right.getRank();
}
