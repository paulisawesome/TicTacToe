/*
 * Square.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef SQUARE_H_
#define SQUARE_H_

namespace TickTackToe {

#define SQUARE_EMPTY    ' '
#define SQUARE_X		'X'
#define SQUARE_Y		'Y'

class Square {
	char value;

public:
	Square();
	virtual ~Square();

	Square operator=(const Square &b);

	char getValue() const;
	bool setValue(const char);
	void reset();
};

} /* namespace TickTackToe */

#endif /* SQUARE_H_ */
