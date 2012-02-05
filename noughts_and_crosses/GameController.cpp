/*
 * StatePlaying.cpp
 *
 *  Created on: Feb 2, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "GameController.h"
#include "functions.h"
#include "colours.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

Game_Controller::Game_Controller() {
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    message = NULL;
    font = TTF_OpenFont("Resource/OptimusPrinceps.ttf",24);
    message = TTF_RenderText_Solid( font, "The quick brown fox jumps over the lazy dog", WHITE );
}

Game_Controller::~Game_Controller() {
	SDL_FreeSurface(message);
    TTF_CloseFont(font);
}

void Game_Controller::MouseDown(int button, int x, int y) {
    apply_surface(x,y,message,screen);
    if (button == SDL_BUTTON_RIGHT) {
    	SDL_FillRect(screen,NULL,0);
    }
    SDL_Flip( screen );
}
