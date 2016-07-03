/*
 * Board.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <list>
#include "Square.h"

namespace TickTackToe {

#define BOARD_STALEMATE '-'
#define DIMLEN 3

struct Move {
	int row;
	int col;
	char val;
	int score;

	Move() { score = 0; row = -1; col = -1; val = 0; };
	Move(int score, char val) { this->score = score; row = -1; col = -1; this->val = val; };
};

class Board {
public:
	Board();
	explicit Board(const Board & b);
	virtual ~Board();

	void getLegalMoves(std::list<Move>& moves, char player);
	Board * getSuccessor(Move move);
	int evaluateScore(char player);
	char victor();
	void print();
	bool setSquare(int row, int col, char val);
	void reset();

private:
	Square squares[DIMLEN][DIMLEN];
};

} /* namespace TickTackToe */

#endif /* BOARD_H_ */
