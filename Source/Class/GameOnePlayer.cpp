/*
 * GameOnePlayer.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "functions.h"
#include "GameOnePlayer.h"
#include "screen.h"
#include "fsm.h"
#include "event.h"
#include "constants.h"
#include "font.h"
#include "types.h"

Game_OnePlayer::Game_OnePlayer(eDifficulty difficulty) : board() {
	background = load_image("Resource/background.png");
	winMessage = TTF_RenderText_Blended(font,"You won!",BLACK);
	loseMessage = TTF_RenderText_Blended(font,"You lost! Better luck next time.",BLACK);
	drawMessage = TTF_RenderText_Blended(font,"It's a draw.",BLACK);
	difficultyLevel = difficulty;
}

Game_OnePlayer::~Game_OnePlayer() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(winMessage);
	SDL_FreeSurface(loseMessage);
	SDL_FreeSurface(drawMessage);
}

void Game_OnePlayer::handle_events(){
	GameState::handle_events();
	wins = board.check_wins();
}

void Game_OnePlayer::do_logic(){
	if (wins == NO_WIN) {
		if (leftMouse.pressed) {
			//If the click was inside the board
			int relX = leftMouse.press.x - board.x;
			int relY = leftMouse.press.y - board.y;

			if ((relX > 0) && (relY > 0) && (relX < board.width) && (relY < board.height)) {
				//Find which cell it was in
				int cellX = (3*relX) / board.width;
				int cellY = (3*relY) / board.height;
				if ((board.place_piece(PIECE_CROSS, cellX, cellY) != 1) && (board.check_wins() == NO_WIN)) {
					computer_move();
				}
			}
		}
	}
}

void Game_OnePlayer::render(){
	apply_surface(0,0,background,screen);
	board.render();
	switch (wins) {
	case WIN_CROSS:
		apply_surface(100,520,winMessage,screen);
		break;
	case WIN_NOUGHT:
		apply_surface(100,520,loseMessage,screen);
		break;
	case DRAW:
		apply_surface(100,520,drawMessage,screen);
		break;
	}
}

void Game_OnePlayer::computer_move() {
	switch (difficultyLevel) {
	case DIFFICULTY_RANDOM:
		random_move();
		break;
	}
}

void Game_OnePlayer::random_move() {
	int row, col, place;
	do {
	place = SDL_GetTicks() % 9;
	row = place % 3;
	col = place / 3;
	} while (board.place_piece(PIECE_NOUGHT,row,col) == 1);
}
