/*
 * constants.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int SCREEN_BPP = 32;

const int FRAMES_PER_SECOND = 20;
const int TICKS_PER_FRAME = 1000 / FRAMES_PER_SECOND;

enum GameStates
{
    STATE_NULL,
    STATE_MENU,
    STATE_GAME_ONEPLAYER,
    STATE_GAME_TWOPLAYER,
    STATE_EXIT
};

//colours
const SDL_Colour WHITE = {0,0,0};
const SDL_Colour BLACK = {255,255,255};


#endif /* CONSTANTS_H_ */
