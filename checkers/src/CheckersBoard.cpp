//#include "include\CheckersBoard.h"
//
//CheckersBoard::CheckersBoard( size_t width, size_t height ) : Board( width, height ) 
//{
//	std::string sym = "O";
//	for ( size_t j = 0; j < height_; ++j )
//	{
//		for ( size_t i = 0; i < width_; ++i )
//		{
//			if (  j == 3 || j == 4 )
//			{
//				sym = "X";
//				continue;
//			}
//
//			if ( j % 2 == 0 && i % 2 == 1 )
//				pieces_[i * width_ + j].symbol(sym);
//			if ( j % 2 == 1 &&  i % 2 == 0 )
//				pieces_[i * width_ + j].symbol(sym);
//		}
//	}
//}
//
//// process player moves
//void CheckersBoard::move( const Player& player )
//{
//}
//
//// validate player moves
//bool CheckersBoard::isValidMove( const Piece& piece, const Position& position ) const
//{
//	return true;
//}
//
//
//// check for end game state
//bool CheckersBoard::isEndGame() const
//{
//	return false;
//}