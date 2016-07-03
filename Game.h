/*
 * Game.h
 *
 *  Created on: Jul 1, 2016
 *      Author: paul
 */

#ifndef GAME_H_
#define GAME_H_

#include <sstream>
#include "Board.h"

namespace TicTacToe {

class Game {
	Board board;
	char currentPlayer;

	int getNumber(std::istringstream &iss);

public:
	Game();
	virtual ~Game();

	void run();
};

} /* namespace TickTackToe */

#endif /* GAME_H_ */
