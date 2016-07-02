/*
 * Game.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef GAME_H_
#define GAME_H_

#include <string>
#include "Board.h"

namespace TickTackToe {

class Game {
	Board board;
	char currentPlayer;

	int stringToNumber(const std::string &str);

public:
	Game();
	virtual ~Game();

	void run();
};

} /* namespace TickTackToe */

#endif /* GAME_H_ */
