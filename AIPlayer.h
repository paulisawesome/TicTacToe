/*
 * AIPlayer.h
 *
 *  Created on: Jul 2, 2016
 *      Author: paul
 */

#ifndef AIPLAYER_H_
#define AIPLAYER_H_

#include "Board.h"

namespace TicTacToe {

class AIPlayer {
	char player;

	Move getValue(Board *board, char player);
	Move maxValue(Board *board, char player);
	Move minValue(Board *board, char player);

public:
	AIPlayer();
	AIPlayer(char player);
	virtual ~AIPlayer();

	Move getMove(Board *board);
};

} /* namespace TickTackToe */

#endif /* AIPLAYER_H_ */
