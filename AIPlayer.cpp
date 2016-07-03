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

namespace TickTackToe {

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
	return getValue(board, this->player, INT_MIN, INT_MAX);
}

Move AIPlayer::getValue(Board *board, char player, int alpha, int beta) {
	/* Check for victory or stalemate */
	char victor = board->victor();
	std::cout << "getValue() victor:" << victor << std::endl;
	if( victor != SQUARE_EMPTY ) {
		/* Evaluate score */
		return Move(board->evaluateScore(player), player);
	}

	/* Get the next agent */
	if( SQUARE_X == player ) {
		player = SQUARE_Y;
	} else {
		player = SQUARE_X;
	}

	/* If this is the AI player try to max */
	if(this->player == player) {
		return maxValue(board, player, alpha, beta);
	} else {
		return minValue(board, player, alpha, beta);
	}
}

Move AIPlayer::maxValue(Board *board, char player, int alpha, int beta) {
	Move move(INT_MIN, player);
	std::list<Move> moves;

	board->getLegalMoves(moves, player);

	while(!moves.empty()) {
		Board * successor = board->getSuccessor(moves.front());
		Move nmove = getValue(successor, player, alpha, beta);

		if(nmove.score > move.score) {
			move = moves.front();
			move.score = nmove.score;
		}
		if( move.score > beta ) {
			return move;
		}
		if( move.score > alpha ) {
			alpha = move.score;
			std::cout << "alpha:" << alpha << std::endl;
		}

		moves.pop_front();
	}

	return move;
}

Move AIPlayer::minValue(Board *board, char player, int alpha, int beta) {
	Move move(INT_MAX, player);
	std::list<Move> moves;

	board->getLegalMoves(moves, player);

	while(!moves.empty()) {
		Board * successor = board->getSuccessor(moves.front());
		Move nmove = getValue(successor, player, alpha, beta);

		if(nmove.score < move.score) {
			move = moves.front();
			move.score = nmove.score;
		}
		if( move.score < alpha ) {
			return move;
		}
		if( move.score < beta ) {
			beta = move.score;
			std::cout << "beta:" << beta << std::endl;
		}

		moves.pop_front();
	}

	return move;
}

} /* namespace TickTackToe */


