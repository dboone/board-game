TARGET := board-game

CXX := clang++
CXXFLAGS := -std=c++11 -Wall -I ./board -I ./chess -I ./checkers 

SOURCES := ./board/src/BoardGameSuite.cpp ./board/src/BoardGame.cpp ./board/src/BoardGameFactory.cpp ./checkers/src/CheckersBoard.cpp ./checkers/src/CheckersGameFactory.cpp ./chess/src/ChessBoard.cpp ./chess/src/ChessGameFactory.cpp ./board/src/Piece.cpp ./board/src/Position.cpp 

OBJECTS := $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

clean:
	rm ./board/*.o
	rm ./chess/*.o
	rm ./checkers/*.o
