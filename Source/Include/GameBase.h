/*
 * GameBase.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef GAMEBASE_H_
#define GAMEBASE_H_

#include "SDL/SDL.h"
#include "GameState.h"
#include "Board.h"

class Game_Base : public GameState {
private:
	SDL_Surface *background;
	Board board;
public:
	Game_Base();
	virtual void render();
	virtual void handle_events();
	virtual ~Game_Base();
	void left_down(int x, int y);
};

#endif /* GAMEBASE_H_ */
