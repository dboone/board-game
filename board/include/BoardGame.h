#ifndef BOARD_GAME_INCLUDED
#define BOARD_GAME_INCLUDED

#include <vector>
#include "include/Player.h"
#include "include/Board.h"
#include "include/BoardGameFactory.h"

// TODO - right now this is centered around the Board class
//        but it would make more sense if it was there was
//        some interface IBoardGame
class BoardGame
{
public:
  BoardGame( const std::shared_ptr< BoardGameFactory > factory );
  
  void playGame();
  
private:
  std::shared_ptr< Board > board_;
  std::vector< Player > players_;
};

#endif // BOARD_GAME_INCLUDED
