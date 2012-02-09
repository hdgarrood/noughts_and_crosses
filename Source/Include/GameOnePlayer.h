/*
 * GameOnePlayer.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef GAMEONEPLAYER_H_
#define GAMEONEPLAYER_H_

#include "GameState.h"

class Game_OnePlayer : public GameState {
public:
	Game_OnePlayer();
	void handle_events();
	void do_logic();
	void render();
};

#endif /* GAMEONEPLAYER_H_ */
