/*
 * AIPlayer.cpp
 *
 *  Created on: Jul 2, 2016
 *      Author: paul
 */
#include <climits>
#include <algorithm> /* std::max */
#include <list>

#include <iostream>

#include "AIPlayer.h"
#include "Board.h"

namespace TicTacToe {

#define OTHER_PLAYER( player ) (player == SQUARE_X) ? SQUARE_Y : SQUARE_X

AIPlayer::AIPlayer() {
	player = SQUARE_Y;

}

AIPlayer::AIPlayer(char player) {
	this->player = player;
}

AIPlayer::~AIPlayer() {
	// TODO Auto-generated destructor stub
}

Move AIPlayer::getMove(Board *board) {
	return getValue(board, OTHER_PLAYER(this->player) );
}

Move AIPlayer::getValue(Board *board, char player) {
	/* Check for victory or stalemate */
	char victor = board->victor();
	if( victor != SQUARE_EMPTY ) {
		/* Evaluate score */
		return Move(board->evaluateScore(player), player);
	}

	/* Get the next agent */
	player = OTHER_PLAYER(player);

	/* If this is the AI player try to max */
	if(this->player == player) {
		return maxValue(board, player);
	} else {
		return minValue(board, player);
	}
}

Move AIPlayer::maxValue(Board *board, char player) {
	Move move(INT_MIN, player);
	std::list<Move> moves;

	board->getLegalMoves(moves, player);

	while(!moves.empty()) {
		Board * successor = board->getSuccessor(moves.front());
		Move nmove = getValue(successor, player);

		if(nmove.score > move.score) {
			move = moves.front();
			move.score = nmove.score;
		}

		moves.pop_front();
	}

	return move;
}

Move AIPlayer::minValue(Board *board, char player) {
	Move move(INT_MAX, player);
	std::list<Move> moves;

	board->getLegalMoves(moves, player);

	while(!moves.empty()) {
		Board * successor = board->getSuccessor(moves.front());
		Move nmove = getValue(successor, player);

		if(nmove.score < move.score) {
			move = moves.front();
			move.score = nmove.score;
		}

		moves.pop_front();
	}

	return move;
}

} /* namespace TickTackToe */


