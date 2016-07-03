/*
 * Game.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */
#include <iostream>
#include <sstream>
#include <string>

#include "AIPlayer.h"
#include "Board.h"
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
	AIPlayer ai(SQUARE_Y);

	board.print();

	do {
		/* Get the move */
		do {
			cout << currentPlayer << ": ";

			int row = -1;
			int col = -1;

			if(SQUARE_X == currentPlayer) {
				string move;
				getline(cin, move);
				istringstream iss(move);

				row = getNumber(iss);
				col = getNumber(iss);
			} else { /* AI Player */
				Move move = ai.getMove(&board);
				row = move.row;
				col = move.col;
				cout << row << " " << col << endl;
			}

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
