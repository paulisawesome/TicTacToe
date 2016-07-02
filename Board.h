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

class Board {
private:
	int rows;
	int cols;
	Square **squares;

public:
	Board();
	virtual ~Board();

	void print();
};

} /* namespace TickTackToe */

#endif /* BOARD_H_ */
