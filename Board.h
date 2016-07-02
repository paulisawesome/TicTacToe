/*
 * Board.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Square.h"

namespace TickTackToe {

#define BOARD_STALEMATE '-'

class Board {
private:
	int dimLen;
	Square **squares;

public:
	Board();
	virtual ~Board();

	char victor();
	void print();
	bool setSquare(int row, int col, char val);
	void reset();
};

} /* namespace TickTackToe */

#endif /* BOARD_H_ */
