/*
 * Square.cpp
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#include "Square.h"

namespace TickTackToe {

Square::Square() {
	this->value = ' ';

}

Square::~Square() {
	// TODO Auto-generated destructor stub
}

char Square::GetValue() const {
	return this->value;
}

void Square::SetValue(const char value) {
	if(this->value == ' ') {
		if(value == 'x' || value == 'X') {
			this->value = 'X';
		} else if( value == 'y' || value == 'Y' ) {
			this->value = 'Y';
		}
	}
}

} /* namespace TickTackToe */
