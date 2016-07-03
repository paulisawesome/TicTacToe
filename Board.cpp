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
}

Board::Board(const Board & b) {
	for(int row = 0; row < DIMLEN; row++) {
		for(int col = 0; col < DIMLEN; col++) {
			this->squares[row][col] = b.squares[row][col];
		}
	}
}

Board::~Board() {
}


void Board::getLegalMoves(std::list<Move>& moves, char player) {
	for(int row = 0; row < DIMLEN; row++) {
		for(int col = 0; col < DIMLEN; col++) {
			if(SQUARE_EMPTY == this->squares[row][col].getValue()) {
				Move move;
				move.row = row;
				move.col = col;
				move.val = player;

				moves.push_back(move);
			}
		}
	}
}


Board * Board::getSuccessor(Move move) {
	Board * newBoard = new Board(*this);
	newBoard->setSquare(move.row, move.col, move.val);
	return newBoard;
}


int Board::evaluateScore(char player) {
	char victor = this->victor();
	char other;

	if(player == SQUARE_X) {
		other = SQUARE_Y;
	} else {
		other = SQUARE_X;
	}

	if(player == victor) {
		return 1000;
	} else if(other == victor) {
		return -1000;
	} else if(BOARD_STALEMATE == victor) {
		return -100;
	} else {
		return 0; // This is goint to make the AI play the first available spot always
	}
}


char Board::victor() {
	int row;
	int col;
	char victor;

	/* Check the rows for a victor */
	for(row = 0; row < DIMLEN; row++) {
		victor = squares[row][0].getValue();

		if(victor != SQUARE_EMPTY) {
			for(col = 1; col < DIMLEN; col++) {
				if(victor != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(col == DIMLEN) {
				return victor;
			}
		}
	}

	/* Check the cols for a victorner */
	for(col = 0; col < DIMLEN; col++) {
		victor = squares[0][col].getValue();

		if(victor != SQUARE_EMPTY) {
			for(row = 1; row < DIMLEN; row++) {
				if(victor != squares[row][col].getValue()) {
					/* Non-consecutive value */
					break;
				}
			}

			if(row == DIMLEN) {
				return victor;
			}
		}
	}

	/* Check the descending diagonal */
	victor = squares[0][0].getValue();
	if(victor != SQUARE_EMPTY) {
		for(row = 1; row < DIMLEN; row++) {
			if(victor != squares[row][row].getValue()) {
				break;
			}
		}

		if(row == DIMLEN) {
			return victor;
		}
	}

	/* Check the ascending diagonal */
	victor = squares[0][DIMLEN - 1].getValue();
	if(victor != SQUARE_EMPTY) {
		for(row = 1; row < DIMLEN; row++) {
			if(victor != squares[row][DIMLEN - row - 1].getValue()) {
				break;
			}
		}

		if(row == DIMLEN) {
			return victor;
		}
	}

	/* Check for stalemate */
	bool stalemate = true;
	for(row = 0; row < DIMLEN && stalemate; row++) {
		for(col = 0; col < DIMLEN && stalemate; col++) {
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
	for(int col = 0; col < (DIMLEN *2) + 1; col++) {
		cout << "-";
	}
	cout << endl;


	for(int row = 0; row < DIMLEN; row++) {
		cout << "|";

		for(int col = 0; col < DIMLEN; col++) {
			cout << squares[row][col].getValue() << "|";
		}

		cout << endl;

		/* Print the bottom */
		for(int col = 0; col < (DIMLEN *2) + 1; col++) {
			cout << "-";
		}
		cout << endl;
	}
}


bool Board::setSquare(int row, int col, char val) {
	if(row >= 0 && row < DIMLEN && col >= 0 && col < DIMLEN ) {
		return squares[row][col].setValue(val);
	}
	return false;
}



void Board::reset() {
	for(int row = 0; row < DIMLEN; row++) {
		for(int col = 0; col < DIMLEN; col++) {
			squares[row][col].reset();
		}
	}
}


} /* namespace TickTackToe */
