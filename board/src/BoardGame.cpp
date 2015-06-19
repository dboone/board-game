#include "include/BoardGame.h"

BoardGame::BoardGame( const std::shared_ptr< BoardGameFactory > factory ) :
 board_( factory->createBoard() )
{
  players_.push_back( Player( "Player 0", "white" ) );
  players_.push_back( Player( "Player 1", "black" ) );
}

// Utilize the board 
void BoardGame::playGame()
{
  while( !board_->isEndGame() )
    {
      for ( int i = 0; i < 2; ++i )
	{
	  board_->display();
	  board_->move( players_[i] );
	}
    }
}
