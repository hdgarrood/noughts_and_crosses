/*
 * Button.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: Harry
 */

#include "Button.h"
#include "screen.h"
#include "functions.h"

Button::Button(int x, int y) {
	normal = load_image("Resource/button.png");
	active = load_image("Resource/button_active.png");
	pressed = load_image("Resource/button_pressed.png");
	mask.w = 200;
	mask.h = 80;
	mask.x = x;
	mask.y = y;
	current_state = NORMAL;
}

Button::~Button() {
	SDL_FreeSurface(normal);
	SDL_FreeSurface(active);
	SDL_FreeSurface(pressed);
}

bool Button::check_hover(int x, int y) {
	int relX = x - mask.x;
	int relY = y - mask.y;

	if ((relX > 0) && (relY > 0) && (relX < mask.w) && (relY < mask.h))
		return true;
	else return false;
}

void Button::render() {
	switch (current_state) {
	case NORMAL:
		apply_surface(mask.x,mask.y,normal,screen);
		break;
	case ACTIVE:
		apply_surface(mask.x,mask.y,active,screen);
		break;
	case PRESSED:
		apply_surface(mask.x,mask.y,pressed,screen);
		break;
	}
}

void Button::change_state(eButtonState newState) {
	current_state = newState;
}
