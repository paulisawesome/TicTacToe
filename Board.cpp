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

char Board::isVictory() {
	int row;
	int col;
	char win;

	/* Check the rows for a winner */
	for(row = 0; row < dimLen; row++) {
		win = squares[row][0].getValue();

		if(win != SQUARE_EMPTY) {
			for(col = 1; col < dimLen; col++) {
				if(win != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(col == dimLen) {
				return win;
			}
		}
	}

	/* Check the cols for a winner */
	for(col = 0; col < dimLen; col++) {
		win = squares[0][col].getValue();

		if(win != SQUARE_EMPTY) {
			for(row = 1; row < dimLen; row++) {
				if(win != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(row == dimLen) {
				return win;
			}
		}
	}

	/* Check the decending diagonal */
	win = squares[0][0].getValue();
	if(win != SQUARE_EMPTY) {
		for(row = 1; row < dimLen; row++) {
			if(win != squares[row][row].getValue()) {
				win = SQUARE_EMPTY;
			}
		}

		if(row == dimLen) {
			return win;
		}
	}

	/* Check the ascending diagonal */
	win = squares[0][dimLen - 1].getValue();
	if(win != SQUARE_EMPTY) {
		for(row = 1; row < dimLen; row++) {
			if(win != squares[row][dimLen - row - 1].getValue()) {
				win = SQUARE_EMPTY;
			}
		}

		if(row == dimLen) {
			return win;
		}
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

void Board::setSquare(int row, int col, char val) {
	if(row < dimLen && col < dimLen ) {
		squares[row][col].setValue(val);
	}
}



void Board::reset() {
	for(int row = 0; row < dimLen; row++) {
		for(int col = 0; col < dimLen; col++) {
			squares[row][col].reset();
		}
	}
}


} /* namespace TickTackToe */
