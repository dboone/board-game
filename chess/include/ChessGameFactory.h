#ifndef CHESS_FACTORY_INCLUDED
#define CHESS_FACTORY_INCLUDED

#include "include/ChessBoard.h"
#include "include/BoardGameFactory.h"

class ChessGameFactory : public BoardGameFactory
{
public:
  virtual std::shared_ptr< Board > createBoard() const;

  static const size_t SIZE;
};

#endif // CHESS_FACTORY_INCLUDED
