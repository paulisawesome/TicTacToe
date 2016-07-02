/*
 * Board.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */
#include <iostream>

#include "Board.h"

using namespace std;

namespace TickTackToe {

Board::Board() {
	dimLen = 3;

	squares = new Square*[dimLen];
	for(int row = 0; row < dimLen; row++) {
		squares[row] = new Square[dimLen];
	}
}

Board::~Board() {
	for(int row = 0; row < dimLen; row++) {
		delete [] squares[row];
	}
	delete [] squares;
}

char Board::victor() {
	int row;
	int col;
	char victor;

	/* Check the rows for a victorner */
	for(row = 0; row < dimLen; row++) {
		victor = squares[row][0].getValue();

		if(victor != SQUARE_EMPTY) {
			for(col = 1; col < dimLen; col++) {
				if(victor != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(col == dimLen) {
				return victor;
			}
		}
	}

	/* Check the cols for a victorner */
	for(col = 0; col < dimLen; col++) {
		victor = squares[0][col].getValue();

		if(victor != SQUARE_EMPTY) {
			for(row = 1; row < dimLen; row++) {
				if(victor != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(row == dimLen) {
				return victor;
			}
		}
	}

	/* Check the descending diagonal */
	victor = squares[0][0].getValue();
	if(victor != SQUARE_EMPTY) {
		for(row = 1; row < dimLen; row++) {
			if(victor != squares[row][row].getValue()) {
				break;
			}
		}

		if(row == dimLen) {
			return victor;
		}
	}

	/* Check the ascending diagonal */
	victor = squares[0][dimLen - 1].getValue();
	if(victor != SQUARE_EMPTY) {
		for(row = 1; row < dimLen; row++) {
			if(victor != squares[row][dimLen - row - 1].getValue()) {
				break;
			}
		}

		if(row == dimLen) {
			return victor;
		}
	}

	/* Check for stalemate */
	bool stalemate = true;
	for(row = 0; row < dimLen && stalemate; row++) {
		for(col = 0; col < dimLen && stalemate; col++) {
			if(squares[row][col].getValue() == SQUARE_EMPTY) {
				stalemate = false;
			}
		}
	}
	if(stalemate){
		return BOARD_STALEMATE;
	}

	return SQUARE_EMPTY;
}

void Board::print() {
	/* Print the top */
	for(int col = 0; col < (dimLen *2) + 1; col++) {
		cout << "-";
	}
	cout << endl;


	for(int row = 0; row < dimLen; row++) {
		cout << "|";

		for(int col = 0; col < dimLen; col++) {
			cout << squares[row][col].getValue() << "|";
		}

		cout << endl;

		/* Print the bottom */
		for(int col = 0; col < (dimLen *2) + 1; col++) {
			cout << "-";
		}
		cout << endl;
	}
}

bool Board::setSquare(int row, int col, char val) {
	if(row < dimLen && col < dimLen ) {
		return squares[row][col].setValue(val);
	}
	return false;
}



void Board::reset() {
	for(int row = 0; row < dimLen; row++) {
		for(int col = 0; col < dimLen; col++) {
			squares[row][col].reset();
		}
	}
}


} /* namespace TickTackToe */
