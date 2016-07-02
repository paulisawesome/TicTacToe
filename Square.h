/*
 * Square.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef SQUARE_H_
#define SQUARE_H_

namespace TickTackToe {

class Square {
	char value;

public:
	Square();
	virtual ~Square();

	char GetValue() const;
	void SetValue(const char);
};

} /* namespace TickTackToe */

#endif /* SQUARE_H_ */
