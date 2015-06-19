#include "include/ChessBoard.h"

ChessBoard::ChessBoard( size_t width, size_t height ) : Board( width, height )
{
  const std::string WHITE = "white";
  const std::string BLACK = "black";
  
  // create all of the required pieces
  std::shared_ptr< PawnMoveValidator > pawnMove		= std::make_shared< PawnMoveValidator >();
  std::shared_ptr< RookMoveValidator > rookMove		= std::make_shared< RookMoveValidator >();
  std::shared_ptr< KnightMoveValidator > knightMove	= std::make_shared< KnightMoveValidator >();
  std::shared_ptr< BishopMoveValidator > bishopMove	= std::make_shared< BishopMoveValidator >();
  std::shared_ptr< QueenMoveValidator > queenMove	= std::make_shared< QueenMoveValidator >();
  std::shared_ptr< KingMoveValidator > kingMove		= std::make_shared< KingMoveValidator >();
  
  // white pieces
  for ( size_t i = 0; i < ChessGameFactory::SIZE; ++i )
    pieces_.push_back( Piece( Position( 'a'+(char)i, 2 ), "P", WHITE, pawnMove ) );
  
  pieces_.push_back( Piece( Position( 'a', 1 ), "R", WHITE, rookMove ) );
  pieces_.push_back( Piece( Position( 'b', 1 ), "N", WHITE, knightMove ) );
  pieces_.push_back( Piece( Position( 'c', 1 ), "B", WHITE, bishopMove ) );
  pieces_.push_back( Piece( Position( 'd', 1 ), "Q", WHITE, queenMove ) );
  pieces_.push_back( Piece( Position( 'e', 1 ), "K", WHITE, kingMove ) );
  pieces_.push_back( Piece( Position( 'f', 1 ), "B", WHITE, bishopMove ) );
  pieces_.push_back( Piece( Position( 'g', 1 ), "N", WHITE, knightMove ) );
  pieces_.push_back( Piece( Position( 'h', 1 ), "R", WHITE, rookMove ) );
  
  // black pieces
  for ( size_t i = 0; i < ChessGameFactory::SIZE; ++i )
    pieces_.push_back( Piece( Position( 'a'+(char)i, 7 ), "p", BLACK, pawnMove ) );
  
  pieces_.push_back( Piece( Position( 'a', 8 ), "r", BLACK, rookMove ) );
  pieces_.push_back( Piece( Position( 'b', 8 ), "n", BLACK, knightMove ) );
  pieces_.push_back( Piece( Position( 'c', 8 ), "b", BLACK, bishopMove ) );
  pieces_.push_back( Piece( Position( 'd', 8 ), "k", BLACK, queenMove ) );
  pieces_.push_back( Piece( Position( 'e', 8 ), "q", BLACK, kingMove ) );
  pieces_.push_back( Piece( Position( 'f', 8 ), "b", BLACK, bishopMove ) );
  pieces_.push_back( Piece( Position( 'g', 8 ), "n", BLACK, knightMove ) );
  pieces_.push_back( Piece( Position( 'h', 8 ), "r", BLACK, rookMove ) );
}

// process player moves
void ChessBoard::move( const Player& player )
{
  std::cout << "Enter your move command: " << std::endl;
  // a move could be composed of several symbols
  // 1: [file][rank] original position to [file][rank] final position
  // 2: [file][rank] if there is only on piece that can make the move
  // 3: [symbol][file][rank] if there is more than one piece that can make the move
  char file;
  size_t rank;
  std::cin >> file >> rank;
  Position position( file, rank );
  
  // make sure there is a piece that can make the move
  std::vector< Piece >::iterator piece = findPiece( position, player );
  
  if ( piece != pieces_.end() )
    {	// make the move
      piece->move( position );
    }
}

// find the piece that can make the move
std::vector< Piece >::iterator ChessBoard::findPiece( const Position& position, const Player& player )
{
  std::vector< Piece >::iterator piece;
  for ( piece = pieces_.begin(); piece != pieces_.end(); ++piece )
    {
      if ( player.ownsPiece( *piece )            // does the player own this piece?
	   && piece->isValidMove( position )     // can this piece move in this pattern? 
	   && isValidMove( position, *piece ) )  // are there board conflicts?
	{
	  return piece;
	}
    }
  
  //if ( piece == pieces_.end() )
  return pieces_.end();				// not a remotely valid move
}

// validate player moves
// then make sure the move fits with the state of the overall board
// TODO - assuming all pieces are sliding pieces
bool ChessBoard::isValidMove( const Position& position, const Piece& piece ) const
{
  // check for sliding conflicts
  
  return true;
}


// check for end game state
bool ChessBoard::isEndGame() const
{
  return false;
}
