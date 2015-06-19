#include <iostream>

#include "include/BoardGame.h"
#include "include/BoardGameFactory.h"

bool validateGameChoice( std::string choice )
{
  std::transform( choice.begin(), choice.end(), choice.begin(), tolower );

  if ( choice == "chess" )
    return true;
  else if ( choice == "checkers" )
    throw std::string( "Game choice \"checkers\" has not been implemented yet!" );

  return false;
}

void printMenu()
{
  std::cout << "Welcome to the Board Game Suite" << std::endl;
  std::cout << "Hope you want to play a game of Chess." << std::endl;
  std::cout << "Select either \"chess\" or \"checkers\": " << std::endl;
}

std::string getGameChoice()
{
  std::string choice = "none";
  do
    {
      printMenu();

      std::cin >> choice;
    } while( !validateGameChoice( choice ) );

  return choice;
}

int main( int argc, char* argv[] )
{
  try
    {
      std::string gameChoice = getGameChoice();
      std::shared_ptr< BoardGameFactory > factory = BoardGameFactory::getGameFactory( gameChoice );

      BoardGame game( factory );
      game.playGame();
    }
  catch( const std::string& e )
    {
      std::cerr << e << std::endl;
    }
  
  return 0;
}
