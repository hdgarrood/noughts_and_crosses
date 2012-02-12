/*
 * Button.cpp
 *
 *  Created on: Feb 12, 2012
 *      Author: Harry
 */

#include "SDL/SDL_ttf.h"
#include "Button.h"
#include "screen.h"
#include "functions.h"
#include "constants.h"
#include "font.h"
#include <string>

Button::Button(int x, int y, std::string message) {
	normal = load_image("Resource/button.png");
	active = load_image("Resource/button_active.png");
	pressed = load_image("Resource/button_pressed.png");
	mask.w = 200;
	mask.h = 80;
	mask.x = x;
	mask.y = y;
	current_state = NORMAL;
	text = TTF_RenderText_Blended(font,message.c_str(),BLACK);
}

Button::~Button() {
	SDL_FreeSurface(normal);
	SDL_FreeSurface(active);
	SDL_FreeSurface(pressed);
	SDL_FreeSurface(text);
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
	tPoint text_position;
	text_position.x = mask.x + ((mask.w - text->w) / 2);
	text_position.y = mask.y + ((mask.h - text->h) / 2);
	apply_surface(text_position.x,text_position.y,text,screen);
}

void Button::change_state(eButtonState newState) {
	current_state = newState;
}
