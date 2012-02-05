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
	SDL_Surface *screen, *message;
	TTF_Font* font;
public:
	Game_Controller();
	void MouseDown(int button, int x, int y);
	virtual ~Game_Controller();
};

#endif /* STATEPLAYING_H_ */
