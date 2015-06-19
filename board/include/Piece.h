#ifndef PIECE_INCLUDED
#define PIECE_INCLUDED

#include <memory>
#include <vector>
#include <string>
#include <iostream>

#include "include/MoveValidator.h"
#include "include/Position.h"

class Piece
{
public:
  Piece( const Position& position,
	 const std::string& symbol,
	 const std::string& color,
	 std::shared_ptr< MoveValidator > move );
  bool isValidMove( const Position& next ) const;
  
  std::string symbol() const
    {
      return symbol_;
    }
  
  void symbol(const std::string& symbol)
  {
    symbol_ = symbol;
  }
  
  const Position& getPosition() const
  {
    return position_;
  }
  
  void move( const Position& next )
  {
    position_ = next;
  }
  
  std::string getColor() const
    {
      return color_;
    }

private:
  Position position_;
  std::string symbol_;
  std::string color_;
  
  std::shared_ptr< MoveValidator > moveValidator_;
};

#endif // PIECE_INCLUDED
