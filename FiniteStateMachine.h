/*
 * FiniteStateMachine.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef FINITESTATEMACHINE_H_
#define FINITESTATEMACHINE_H_

#include "SDL/SDL.h"
#include "constants.h"
#include "GameState.h"

class Finite_State_Machine {
private:
	int currentStateID;
	int nextStateID;
public:
	Finite_State_Machine();
	void set_next_state( int newState );
	void change_state();
	int get_current_state();
	GameState *currentState;
};

#endif /* FINITESTATEMACHINE_H_ */
