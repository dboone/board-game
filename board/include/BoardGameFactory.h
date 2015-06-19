#ifndef BOARD_GAME_FACTORY_INCLUDED
#define BOARD_GAME_FACTORY_INCLUDED

#include <memory>
#include <string>
#include <vector>
#include <algorithm>

#include "include/Board.h"

// An abstract factory that creates the appropiate game.

class BoardGameFactory
{
public:
  static std::shared_ptr< BoardGameFactory > getGameFactory( std::string gameType );
  
  // to be defined by each subclass
  virtual std::shared_ptr< Board > createBoard() const = 0;
  
  //virtual std::vector< Piece > createPieces() = 0;
  //virtual const std::vector< Player >& createPlayers() = 0;
  
  static const std::string CHESS_GAME;
  static const std::string CHECKERS_GAME;
};

#endif

#include "include/ChessGameFactory.h"
#include "include/CheckersGameFactory.h"
