/*
 * GameOnePlayer.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "GameOnePlayer.h"
#include "screen.h"
#include "fsm.h"
#include "event.h"
#include "constants.h"

Game_OnePlayer::Game_OnePlayer() {
	SDL_FillRect(screen,NULL,0xFF0000FF);
}

void Game_OnePlayer::handle_events(){
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			fsm.set_next_state(STATE_EXIT);
			break;
		case SDL_KEYDOWN:
			fsm.set_next_state(STATE_MENU);
			break;
		}
	}
}
void Game_OnePlayer::do_logic(){}
void Game_OnePlayer::render(){}
