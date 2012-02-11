/*
 * main.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "constants.h"
#include "FiniteStateMachine.h"
#include "GameState.h"
#include "Timer.h"
#include "screen.h"
#include "fsm.h"
#include "event.h"

SDL_Surface *screen = NULL;
SDL_Event event;
Finite_State_Machine fsm;
TTF_Font *font = NULL;

int main( int argc, char* args[] ) {

    Timer timer;

    SDL_Init(SDL_INIT_EVERYTHING);
    screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

    TTF_Init();
    font = TTF_OpenFont("Resource/OptimusPrinceps.ttf",28);

    fsm.set_next_state(STATE_MENU);
    fsm.change_state();

    while (fsm.get_current_state() != STATE_EXIT) {

        timer.start();

        fsm.currentState->handle_events();
        fsm.currentState->do_logic();
        fsm.currentState->render();
        fsm.change_state();

        if (SDL_Flip(screen) == -1) { return -624; }

        int currentTicks = timer.get_ticks();
        if (currentTicks < TICKS_PER_FRAME) { SDL_Delay(TICKS_PER_FRAME - currentTicks); }
    }

    return 0;
}
