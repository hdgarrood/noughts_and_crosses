/*
 * GameTwoPlayer.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef GAMETWOPLAYER_H_
#define GAMETWOPLAYER_H_

#include "GameState.h"
#include "Board.h"
#include "types.h"

class Game_TwoPlayer : public GameState {
private:
	SDL_Surface *background, *noughtsTurnMessage, *crossTurnMessage, *noughtsWinMessage, *crossWinMessage, *drawMessage;
	tMyMouseEvent leftMouse, rightMouse;
	ePiece nextPiece;
	eWinState wins;
public:
	Game_TwoPlayer();
	void handle_events();
	void do_logic();
	void render();
	~Game_TwoPlayer();
	Board board;
};

#endif /* GAMETWOPLAYER_H_ */
