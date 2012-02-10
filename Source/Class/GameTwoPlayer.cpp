/*
 * GameTwoPlayer.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#include "GameTwoPlayer.h"
#include "functions.h"
#include "screen.h"
#include "fsm.h"
#include "event.h"
#include "types.h"

Game_TwoPlayer::Game_TwoPlayer() : board() {
	background = load_image("Resource/background.png");
}

Game_TwoPlayer::~Game_TwoPlayer() {
	SDL_FreeSurface(background);
}

void Game_TwoPlayer::render() {
	apply_surface(0,0,background,screen,NULL);
	board.render();
}

void Game_TwoPlayer::handle_events() {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			fsm.set_next_state(STATE_EXIT);
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.button.button == SDL_BUTTON_LEFT) {
				leftMouse.pressed = true;
				leftMouse.x = event.button.x;
				leftMouse.y = event.button.y;
			}
			break;
		}
	}
}

void Game_TwoPlayer::do_logic() {
	if (leftMouse.pressed) {
		//If the click was inside the board
		int relX = leftMouse.x - board.x;
		int relY = leftMouse.y - board.y;

		if ((relX > 0) && (relY > 0) && (relX < board.width) && (relY < board.height)) {
			//Find which cell it was in
			int cellX = (3*relX) / board.width;
			int cellY = (3*relY) / board.height;
			if (board.place_piece(PIECE_CROSS, cellX, cellY) == -1) {
				//show text: You can't go there.
			}
			else {
				//change whose turn it is
			}
		}
		leftMouse.reset();
	}
}
