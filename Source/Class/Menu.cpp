/*
 * Menu.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "Menu.h"
#include "functions.h"
#include "constants.h"
#include "fsm.h"
#include "screen.h"
#include "event.h"

Menu::Menu() {
	SDL_FillRect(screen,NULL,0x0000FFFF);
}

Menu::~Menu() {
	//TODO
}

void Menu::handle_events() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			fsm.set_next_state(STATE_EXIT);
			break;
		case SDL_KEYDOWN:
			fsm.set_next_state(STATE_GAME_TWOPLAYER);
			break;
		}
	}
}

void Menu::do_logic() {

}

void Menu::render() {

}
