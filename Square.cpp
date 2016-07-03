/*
 * Square.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#include "Square.h"

namespace TickTackToe {

Square::Square() {
	this->value = SQUARE_EMPTY;

}

Square::~Square() {
	// TODO Auto-generated destructor stub
}

Square Square::operator=(const Square &b) {
	if(this != &b) {
		this->value = b.value;
	}
	return *this;
}

char Square::getValue() const {
	return this->value;
}

bool Square::setValue(const char value) {
	bool ret = false;

	if(this->value == SQUARE_EMPTY) {
		if(value == 'x' || value == 'X') {
			this->value = SQUARE_X;
			ret = true;
		} else if( value == 'y' || value == 'Y' ) {
			this->value = SQUARE_Y;
			ret = true;
		}
	}

	return ret;
}

void Square::reset() {
	this->value = SQUARE_EMPTY;
}

} /* namespace TickTackToe */
