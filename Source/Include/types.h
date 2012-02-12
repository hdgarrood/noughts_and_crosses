/*
 * types.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef TYPES_H_
#define TYPES_H_

struct tPoint {
	int x;
	int y;
	void reset() {
		x=0;
		y=0;
	}
};

struct tMyMouseEvent {
	bool pressed;
	bool released;
	tPoint press;
	tPoint release;
	void reset() {
		press.reset();
		release.reset();
		pressed = false;
		released = false;
	}
};

enum eButtonState {
	NORMAL,
	ACTIVE,
	PRESSED
};

enum eGameState {
    STATE_NULL,
    STATE_MENU,
    STATE_GAME_ONEPLAYER,
    STATE_GAME_TWOPLAYER,
    STATE_EXIT
};

enum ePiece {
	PIECE_NULL,
	PIECE_CROSS,
	PIECE_NOUGHT
};

enum eWinState {
	NO_WIN,
	DRAW,
	WIN_NOUGHT,
	WIN_CROSS
};

enum eDifficulty {
	DIFFICULTY_RANDOM,
	DIFFICULTY_NORMAL,
	DIFFICULTY_HARD
};

#endif /* TYPES_H_ */
