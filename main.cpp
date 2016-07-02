#include <iostream>
#include "Board.h"
#include "Game.h"

using namespace TickTackToe;

static void boardTest() {
	Board board;

	board.print();
	std::cout << board.victor() << std::endl;

	/* The following should be winners */
	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,0, SQUARE_X);
	board.setSquare(2,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,1, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);
	board.setSquare(2,1, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,2, SQUARE_X);
	board.setSquare(1,2, SQUARE_X);
	board.setSquare(2,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(0,1, SQUARE_X);
	board.setSquare(0,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(1,0, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);
	board.setSquare(1,2, SQUARE_X);board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(2,0, SQUARE_X);
	board.setSquare(2,1, SQUARE_X);
	board.setSquare(2,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);
	board.setSquare(2,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,2, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);
	board.setSquare(2,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	/* The following should be losses */
	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(0,1, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(0,1, SQUARE_Y);
	board.setSquare(0,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,0, SQUARE_Y);
	board.setSquare(2,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,1, SQUARE_Y);
	board.setSquare(2,2, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(2,0, SQUARE_X);
	board.setSquare(1,1, SQUARE_X);

	board.print();
	std::cout << board.victor() << std::endl;

	board.reset();
	board.setSquare(0,2, SQUARE_X);
	board.setSquare(1,1, SQUARE_Y);
	board.setSquare(2,0, SQUARE_X);
	board.print();
	std::cout << board.victor() << std::endl;

	/* Stalemate Test */
	board.reset();
	board.setSquare(0,0, SQUARE_X);
	board.setSquare(1,0, SQUARE_Y);
	board.setSquare(2,0, SQUARE_Y);
	board.setSquare(0,1, SQUARE_Y);
	board.setSquare(1,1, SQUARE_X);
	board.setSquare(2,1, SQUARE_X);
	board.setSquare(0,2, SQUARE_Y);
	board.setSquare(1,2, SQUARE_X);
	board.setSquare(2,2, SQUARE_Y);
	board.print();
	std::cout << board.victor() << std::endl;

}


int main( int argc, char * argv[] ) {
//	boardTest();

	Game game;
	game.run();
	return 0;
}
