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
const int SCREEN_HEIGHT = 640;
const int SCREEN_BPP = 32;

Game_Controller::Game_Controller() {
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    font = TTF_OpenFont("Resource/OptimusPrinceps.ttf",24);
    restart_message = TTF_RenderText_Solid(font,"Press Space to restart",WHITE);
    board = load_image("Resource/board.png");
    nought = load_image("Resource/nought.png");
    cross = load_image("Resource/cross.png");
    background = load_image("Resource/background.png");
    Reset();
}

Game_Controller::~Game_Controller() {
	SDL_FreeSurface(board);
	SDL_FreeSurface(cross);
	SDL_FreeSurface(nought);
	SDL_FreeSurface(background);
    TTF_CloseFont(font);
}

void Game_Controller::MouseDown(int button, int x, int y) {
	switch (button) {
	case SDL_BUTTON_RIGHT:
		apply_surface(x-82,y-82,nought,screen);
		break;
	case SDL_BUTTON_LEFT:
		apply_surface(x-82,y-82,cross,screen);
		break;
	}
    SDL_Flip( screen );
}

void Game_Controller::KeyDown(int keysym) {
	switch (keysym) {
	case SDLK_SPACE:
		Reset();
		break;
	}
}

void Game_Controller::Reset() {
    apply_surface(0,0,background,screen);
    apply_surface(51,17,board,screen);
    apply_surface(20,550,restart_message,screen);
    SDL_Flip(screen);
}
