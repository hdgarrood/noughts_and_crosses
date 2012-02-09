/*
 * Timer.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 *
 *  NOTE:
 *  	startTicks actually changes during unpause(), so it doesn't actually store
 *  	the time the timer was started if it has been paused.
 *  	Instead, it stores the amount of ticks which should be
 *  	subtracted from the current ticks to get the timer ticks.
 *
 *  	pausedTicks stores the time when the timer was paused.
 *  	It is used to adjust startTicks during unpause()
 */

#ifndef TIMER_H_
#define TIMER_H_

class Timer {
private:
    int startTicks, pausedTicks;
    bool paused, started;
public:
    Timer();
    void start();
    void pause();
    void unpause();
    int get_ticks();
    bool is_started();
    bool is_paused();
};


#endif /* TIMER_H_ */
