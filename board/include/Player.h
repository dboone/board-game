#ifndef PLAYER_INCLUDED
#define PLAYER_INCLUDED

#include <string>
#include "include/Piece.h"

class Player
{
public:
 Player( const std::string& name, const std::string& color ) : name_(name), color_(color)
  {
  }
  
  bool ownsPiece( const Piece& piece ) const
  {
    return color_ == piece.getColor();
  }

private:
  std::string name_;
  std::string color_;
};
#endif
