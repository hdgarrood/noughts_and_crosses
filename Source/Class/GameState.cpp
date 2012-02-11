/*
 * GameState.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "GameState.h"
#include "event.h"
#include "fsm.h"

GameState::~GameState(){}

void GameState::handle_events(){
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			fsm.set_next_state(STATE_EXIT);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				leftMouse.pressed = true;
				leftMouse.x = event.button.x;
				leftMouse.y = event.button.y;
			}
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				fsm.set_next_state(STATE_MENU);
			}
			break;
		}
	}
}
void GameState::do_logic(){}
void GameState::render(){}
