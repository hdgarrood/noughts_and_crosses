/*
 * GameTwoPlayer.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef GAMETWOPLAYER_H_
#define GAMETWOPLAYER_H_

#include "GameBase.h"
#include "Board.h"
#include "types.h"

class Game_TwoPlayer : public GameState {
private:
	SDL_Surface *background;
	tMyMouseEvent leftMouse, rightMouse;
public:
	Game_TwoPlayer();
	void handle_events();
	void do_logic();
	void render();
	~Game_TwoPlayer();
	Board board;
};

#endif /* GAMETWOPLAYER_H_ */
