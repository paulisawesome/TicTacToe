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

char Square::getValue() const {
	return this->value;
}

void Square::setValue(const char value) {
	if(this->value == SQUARE_EMPTY) {
		if(value == 'x' || value == 'X') {
			this->value = SQUARE_X;
		} else if( value == 'y' || value == 'Y' ) {
			this->value = SQUARE_Y;
		}
	}
}

void Square::reset() {
	this->value = SQUARE_EMPTY;
}

} /* namespace TickTackToe */
