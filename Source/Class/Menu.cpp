/*
 * Menu.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "Menu.h"
#include "functions.h"
#include "types.h"
#include "fsm.h"
#include "screen.h"
#include "event.h"

Menu::Menu() : onePlayerButton(220,250,"One Player"), twoPlayerButton(220,350,"Two Player") {
	background = load_image("Resource/background.png");
	title = load_image("Resource/title.png");
}

Menu::~Menu() {
	SDL_FreeSurface(background);
}

void Menu::handle_events() {
	GameState::handle_events();
}

void Menu::do_logic() {
	if (leftMouse.pressed) {
		if (onePlayerButton.check_hover(leftMouse.press.x,leftMouse.press.y)) {
			onePlayerButton.change_state(PRESSED);
		}
		if (twoPlayerButton.check_hover(leftMouse.press.x,leftMouse.press.y)) {
			twoPlayerButton.change_state(PRESSED);
		}
	}
	if (leftMouse.released) {
		if (onePlayerButton.check_hover(leftMouse.release.x,leftMouse.release.y) && onePlayerButton.get_state() == PRESSED)
			fsm.set_next_state(STATE_GAME_ONEPLAYER);
		if (twoPlayerButton.check_hover(leftMouse.release.x,leftMouse.release.y) && twoPlayerButton.get_state() == PRESSED)
			fsm.set_next_state(STATE_GAME_TWOPLAYER);

		onePlayerButton.change_state(NORMAL);
		twoPlayerButton.change_state(NORMAL);
	}
}

void Menu::render() {
	apply_surface(0,0,background,screen);
	apply_surface(45,30,title,screen);
	onePlayerButton.render();
	twoPlayerButton.render();
}
