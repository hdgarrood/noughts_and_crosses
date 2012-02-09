/*
 * Timer.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "Timer.h"
#include "SDL/SDL.h"

Timer::Timer() {
	startTicks = 0;
	pausedTicks = 0;
	paused = false;
	started = false;
}

void Timer::start() {
	startTicks = SDL_GetTicks();
	started = true;
	paused = false;
}

void Timer::pause() {
	pausedTicks = SDL_GetTicks();
	paused = true;
}

void Timer::unpause() {
	startTicks = SDL_GetTicks() - pausedTicks;
	paused = false;
	pausedTicks = 0;
}

int Timer::get_ticks() {
	if (paused) { return pausedTicks; }
	else { return SDL_GetTicks() - startTicks; }
}

bool Timer::is_started() { return started; }
bool Timer::is_paused() { return paused; }
