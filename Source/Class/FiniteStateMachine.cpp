/*
 * FiniteStateMachine.cpp
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#include "FiniteStateMachine.h"
#include "Menu.h"
#include "GameOnePlayer.h"
#include "GameTwoPlayer.h"
#include "types.h"

Finite_State_Machine::Finite_State_Machine() {
	currentStateID = STATE_NULL;
	nextStateID = STATE_NULL;
	currentState = NULL;
}

void Finite_State_Machine::set_next_state(int newState) {
    nextStateID = newState;
}

void Finite_State_Machine::change_state() {

    if( nextStateID != STATE_NULL ) {
        delete currentState;
        switch (nextStateID) {
        case STATE_MENU:
        	currentState = new Menu;
        	break;
        case STATE_GAME_ONEPLAYER:
        	currentState = new Game_OnePlayer(DIFFICULTY_RANDOM);
        	break;
        case STATE_GAME_TWOPLAYER:
        	currentState = new Game_TwoPlayer;
        	break;
        }

        currentStateID = nextStateID;
        nextStateID = STATE_NULL;
    }
}

int Finite_State_Machine::get_current_state() {
	return currentStateID;
}
