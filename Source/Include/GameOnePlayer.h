/*
 * GameOnePlayer.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef GAMEONEPLAYER_H_
#define GAMEONEPLAYER_H_

#include "GameState.h"
#include "Board.h"
#include "types.h"

class Game_OnePlayer : public GameState {
private:
	Board board;
	SDL_Surface *background,*winMessage, *loseMessage, *drawMessage;
	eWinState wins;
	eDifficulty difficultyLevel;
	void computer_move();
	void random_move();
public:
	Game_OnePlayer(eDifficulty difficulty);
	void handle_events();
	void do_logic();
	void render();
	~Game_OnePlayer();
};

#endif /* GAMEONEPLAYER_H_ */
