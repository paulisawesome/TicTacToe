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
	rows = 3;
	cols = 3;

	squares = new Square*[rows];
	for(int row = 0; row < this->rows; row++) {
		squares[row] = new Square[cols];
	}
}

Board::~Board() {
	for(int row = 0; row < this->rows; row++) {
		delete [] squares[row];
	}
	delete [] squares;
}

void Board::print() {
	/* Print the top */
	for(int col = 0; col < (cols *2) + 1; col++) {
		cout << "-";
	}
	cout << endl;


	for(int row = 0; row < this->rows; row++) {
		cout << "|";

		for(int col = 0; col < this->cols; col++) {
			cout << squares[row][col].GetValue() << "|";
		}

		cout << endl;

		/* Print the bottom */
		for(int col = 0; col < (cols *2) + 1; col++) {
			cout << "-";
		}
		cout << endl;
	}
}


} /* namespace TickTackToe */
