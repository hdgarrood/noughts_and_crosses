/*
 * Board.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "types.h"

class Board {
private:
	ePiece pieces[3][3];
	SDL_Surface *board, *nought, *cross;
	ePiece check_horizontal_wins();
	ePiece check_vertical_wins();
	ePiece check_diagonal_wins();
	eWinState resolve_wins(ePiece piece);
public:
	Board();
	void handle_events();
	void render();
	int place_piece(ePiece piece, int row, int column);
	eWinState check_wins();
	~Board();
	int x, y;
	const static int width = 496;
	const static int height = 496;
};

#endif /* BOARD_H_ */
