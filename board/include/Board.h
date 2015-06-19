#ifndef BOARD_INCLUDED
#define BOARD_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <cassert>

#include "include/Piece.h"
#include "include/Player.h"

// This class assumes that we are using a 2 dimensional rectangular board
// TODO - need a way to keep track of player 1 pieces versus player 2 pieces
class Board
{
public:
 Board() : width_(0), height_(0) 
    {
    }
  
 Board( size_t width, size_t height )
   : width_(width), 
    height_(height)
    {
    }
  
  const Piece& operator()( size_t i, size_t j ) const
  {
    assert( j * width_ + i < pieces_.size() );
    return pieces_[j * width_ + i];
  }
  
  void display()
  {
    // TODO - system specific
    std::system("clear");
    
    // if we only store the pieces in play, i.e. not empty squares, 
    // then we have to spend some extra resources to display them.
    
    // O(n) where n is the number of pieces
    std::vector< std::string > fullBoard( width_ * height_, " " );
    
    std::vector< Piece >::const_iterator it;
    for ( it = pieces_.begin(); it != pieces_.end(); ++it )
      {
	size_t i = it->getPosition().getFile() - 'a';
	size_t j = it->getPosition().getRank() - 1;
	
	fullBoard[ j * width_ + i ] = it->symbol();
      }
    
    std::cout << "  a  b  c  d  e  f  g  h " << std::endl;
    
    for ( int j = height_ - 1; j >= 0; --j )
      {
	std::cout << j + 1 << std::flush;
	for ( int i = 0; i < width_; ++i )
	  {
	    std::cout << "[" << fullBoard[ j * width_ + i ] << "]" << std::flush;
	  }
	std::cout << std::endl;
      }
  }
  
  // move a piece on the board
  virtual void move( const Player& player ) = 0;
  
  // board level move validation
  virtual bool isValidMove( const Position& position, const Piece& piece ) const = 0;

  // TODO - this does not belong in the board class
  virtual bool isEndGame() const = 0;
  
 protected:
  size_t width_;
  size_t height_;
  std::vector< Piece > pieces_;
};

#endif // BOARD_INCLUDED
