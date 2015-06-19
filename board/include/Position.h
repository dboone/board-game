#ifndef POSITION_INCLUDED
#define POSITION_INCLUDED

#include <cstdio>

class Position
{
public:
 Position() : file_('\0'), rank_(0) 
    {
    } 
 Position( char file, size_t rank ) : file_(file), rank_(rank)
  {
  }
  
  char getFile() const
  {
    return file_;
  }
  
  size_t getRank() const
  {
    return rank_;
  }
  
  bool operator==( const Position& right ) const;
  
 private:
  char   file_;
  size_t rank_;
};

#endif // POSITION_INCLUDED
