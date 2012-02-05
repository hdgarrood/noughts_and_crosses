/*
 * GameController.cpp
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
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

Game_Controller::Game_Controller() {
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    font = TTF_OpenFont("Resource/OptimusPrinceps.ttf",24);
    board = load_image("Resource/board.png");
    nought = load_image("Resource/nought.png");
    cross = load_image("Resource/cross.png");
    background = load_image("Resource/background.png");
    apply_surface(0,0,background,screen);
    apply_surface(51,17,board,screen);
    SDL_Flip(screen);
}

Game_Controller::~Game_Controller() {
	SDL_FreeSurface(board);
	SDL_FreeSurface(cross);
	SDL_FreeSurface(nought);
    TTF_CloseFont(font);
}

void Game_Controller::MouseDown(int button, int x, int y) {
	switch (button) {
	case SDL_BUTTON_RIGHT:
		apply_surface(x,y,nought,screen);
		break;
	case SDL_BUTTON_LEFT:
		apply_surface(x,y,cross,screen);
		break;
	}
    SDL_Flip( screen );
}
