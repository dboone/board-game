#include "include/ChessGameFactory.h"

const size_t ChessGameFactory::SIZE = 8;

std::shared_ptr< Board > ChessGameFactory::createBoard() const
{
  // create the board
  return std::make_shared< ChessBoard >( ChessBoard(SIZE, SIZE) );
}
