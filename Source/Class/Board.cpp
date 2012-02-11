/*
 * Board.cpp
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#include "SDL/SDL.h"
#include "Board.h"
#include "constants.h"
#include "functions.h"
#include "screen.h"

Board::Board() {
	board = load_image("Resource/board.png");
	nought = load_image("Resource/nought.png");
	cross = load_image("Resource/cross.png");

	for (int i=0;i!=3;i++) {
		for (int j=0;j!=3;j++) {
			pieces[i][j] = PIECE_NULL;
		}
	}

	x = 51;
	y = 17;
}

Board::~Board() {
	SDL_FreeSurface(board);
	SDL_FreeSurface(nought);
	SDL_FreeSurface(cross);
}

int Board::place_piece(ePiece piece, int row, int column) {
	if (pieces[row][column] == PIECE_NULL) {
		pieces[row][column] = piece;
		return 0;
	}
	return 1;
}

eWinState Board::check_wins() {
	ePiece winPiece = PIECE_NULL;

	winPiece = check_horizontal_wins();
	if (winPiece != PIECE_NULL) { return resolve_wins(winPiece); }

	winPiece = check_vertical_wins();
	if (winPiece != PIECE_NULL) { return resolve_wins(winPiece); }

	//diagonal wins
	winPiece = check_diagonal_wins();
	if (winPiece != PIECE_NULL) { return resolve_wins(winPiece); }

	//is the board full?
	bool boardFull = true;
	for (int i=0;i!=3;i++) {
		for (int j=0;j!=3;j++) {
			if (pieces[i][j] == PIECE_NULL) { boardFull = false; }
			if (!boardFull) break;
		}
	}
	if (boardFull) return DRAW;
	return NO_WIN;
}

void Board::render() {
	apply_surface(x,y,board,screen,NULL);

	for (int i=0;i!=3;i++) {
		for (int j=0;j!=3;j++) {

			switch (pieces[i][j]) {
			case PIECE_NULL:
				break;
			case PIECE_NOUGHT:
				apply_surface(x+(i*width/3),y+(j*height/3),nought,screen,NULL);
				break;
			case PIECE_CROSS:
				apply_surface(x+(i*width/3),y+(j*height/3),cross,screen,NULL);
				break;

			}
		}
	}
}

ePiece Board::check_horizontal_wins() {
	for (int i=0;i!=3;i++) {
		if ((pieces[i][0] == pieces[i][1]) && (pieces[i][1] == pieces [i][2])) {
			 return pieces[i][0];
		}
	}
	return PIECE_NULL;
}

ePiece Board::check_vertical_wins() {
	for (int i=0;i!=3;i++) {
		if ((pieces[0][i] == pieces[1][i]) && (pieces[1][i] == pieces [2][i])) {
			return pieces[0][i];
		}
	}
	return PIECE_NULL;
}

ePiece Board::check_diagonal_wins() {
	if ((pieces[0][0] == pieces [1][1]) && (pieces[1][1] == pieces [2][2])) {
		return pieces[0][0];
	}

	if ((pieces[0][2] == pieces [1][1]) && (pieces[1][1] == pieces [2][0])) {
		return pieces[0][2];
	}
	return PIECE_NULL;
}

eWinState Board::resolve_wins(ePiece piece) {
	if (piece == PIECE_NOUGHT) { return WIN_NOUGHT; }
	else if (piece == PIECE_CROSS) { return WIN_CROSS; }

	return NO_WIN;
}
