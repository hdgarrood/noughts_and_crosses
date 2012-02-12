/*
 * GameTwoPlayer.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "GameTwoPlayer.h"
#include "functions.h"
#include "screen.h"
#include "fsm.h"
#include "event.h"
#include "types.h"
#include "font.h"

Game_TwoPlayer::Game_TwoPlayer() : board() {
	background = load_image("Resource/background.png");
	noughtsTurnMessage = TTF_RenderText_Blended(font,"Noughts to move.",BLACK);
	crossTurnMessage = TTF_RenderText_Blended(font,"Crosses to move.",BLACK);
	noughtsWinMessage = TTF_RenderText_Blended(font,"Noughts win!",BLACK);
	crossWinMessage = TTF_RenderText_Blended(font,"Crosses win!",BLACK);
	drawMessage = TTF_RenderText_Blended(font,"It's a draw.",BLACK);
	nextPiece = PIECE_CROSS;
}

Game_TwoPlayer::~Game_TwoPlayer() {
	SDL_FreeSurface(background);
	SDL_FreeSurface(noughtsTurnMessage);
	SDL_FreeSurface(noughtsWinMessage);
	SDL_FreeSurface(crossTurnMessage);
	SDL_FreeSurface(crossWinMessage);
	SDL_FreeSurface(drawMessage);
}

void Game_TwoPlayer::handle_events() {
	GameState::handle_events();
	wins = board.check_wins();
}

void Game_TwoPlayer::do_logic() {
	if (wins == NO_WIN) {
		if (leftMouse.pressed) {
			//If the click was inside the board
			int relX = leftMouse.press.x - board.x;
			int relY = leftMouse.press.y - board.y;

			if ((relX > 0) && (relY > 0) && (relX < board.width) && (relY < board.height)) {
				//Find which cell it was in
				int cellX = (3*relX) / board.width;
				int cellY = (3*relY) / board.height;
				if (board.place_piece(nextPiece, cellX, cellY) != 1) {
					if (nextPiece == PIECE_CROSS) { nextPiece = PIECE_NOUGHT; }
					else { nextPiece = PIECE_CROSS; }
				}
			}
		}
	}
}

void Game_TwoPlayer::render() {
	apply_surface(0,0,background,screen,NULL);
	board.render();
	switch (wins) {
	case WIN_CROSS:
		apply_surface(100,520,crossWinMessage,screen,NULL);
		break;
	case WIN_NOUGHT:
		apply_surface(100,520,noughtsWinMessage,screen,NULL);
		break;
	case DRAW:
		apply_surface(100,520,drawMessage,screen,NULL);
		break;
	case NO_WIN:
		if (nextPiece == PIECE_CROSS) { apply_surface(100,520,crossTurnMessage,screen,NULL); }
		else { apply_surface(100,520,noughtsTurnMessage,screen,NULL); }
		break;
	}
}
