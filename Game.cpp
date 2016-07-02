/*
 * Game.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */
#include <iostream>
#include <sstream>
#include <string>

#include "Game.h"
#include "Square.h"

using namespace std;

namespace TickTackToe {

Game::Game() {
	currentPlayer = SQUARE_X;
}

Game::~Game() {
	// TODO Auto-generated destructor stub
}

void Game::run() {
	char victor;
	bool valid;

	board.print();

	do {
		/* Get the move */
		do {
			cout << currentPlayer << ": ";

			string move;
			getline(cin, move);
			istringstream iss(move);

			int row = getNumber(iss);
			int col = getNumber(iss);
			cout << "Hello " << row << " " << col << endl;

			valid = board.setSquare(row, col, currentPlayer);
			if(!valid) {
				cout << "Invalid move!" << endl;
			}
		} while( !valid );

		board.print();

		/* Switch the current player */
		if(SQUARE_X == currentPlayer) {
			currentPlayer = SQUARE_Y;
		} else {
			currentPlayer = SQUARE_X;
		}

		/* Check for victory */
		victor = this->board.victor();
	} while( SQUARE_EMPTY == victor && BOARD_STALEMATE != victor );

	if(BOARD_STALEMATE == victor) {
		cout << "Stalemate!" << endl;
	} else {
		cout << "Winner! " << victor << endl;
	}
}


int Game::getNumber(istringstream &iss) {
	int result;
	return (iss >> result) ? result : -1;
}

} /* namespace TickTackToe */
