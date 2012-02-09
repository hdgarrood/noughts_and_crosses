/*
 * GameState.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

class GameState
{
public:
    virtual void handle_events() = 0;
    virtual void do_logic() = 0;
    virtual void render() = 0;
    virtual ~GameState();
};

#endif /* GAMESTATE_H_ */
