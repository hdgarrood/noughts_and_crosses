/*
 * StatePlaying.h
 *
 *  Created on: Feb 2, 2012
 *      Author: Harry
 */

#ifndef STATEPLAYING_H_
#define STATEPLAYING_H_

class Game_Controller {
private:
	SDL_Surface *screen, *board, *nought, *cross, *background, *restart_message;
	TTF_Font* font;
	void Reset();
public:
	Game_Controller();
	void MouseDown(int button, int x, int y);
	void KeyDown(int keysym);
	virtual ~Game_Controller();
};

#endif /* STATEPLAYING_H_ */
