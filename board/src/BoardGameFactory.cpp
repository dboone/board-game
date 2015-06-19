#include "include/BoardGameFactory.h"

const std::string BoardGameFactory::CHESS_GAME = "CHESS";
const std::string BoardGameFactory::CHECKERS_GAME = "CHECKERS";

std::shared_ptr< BoardGameFactory > BoardGameFactory::getGameFactory( std::string gameType )
{
  // convert to uppercase
  std::transform( gameType.begin(), gameType.end(), gameType.begin(), toupper );
  
  if ( gameType == CHESS_GAME )
    {
      return std::make_shared< ChessGameFactory >();
    }
  //else if ( gameType == CHECKERS_GAME )
  //{
  //	return std::make_shared< CheckersGameFactory >();
  //}
  else
    {
      throw std::string( "Unknown game choice!" );
    }
}
