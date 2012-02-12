/*
 * Button.h
 *
 *  Created on: Feb 12, 2012
 *      Author: Harry
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include "SDL/SDL.h"
#include "types.h"
#include <string>

class Button {
private:
	SDL_Surface *normal, *active, *pressed, *text;
	SDL_Rect mask;
	eButtonState current_state;
public:
	Button(int x, int y, std::string message);
	virtual ~Button();
	bool check_hover(int x, int y);
	void render();
	void change_state(eButtonState newState);
	eButtonState get_state();
};

#endif /* BUTTON_H_ */
