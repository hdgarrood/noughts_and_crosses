/*
 * Menu.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef MENU_H_
#define MENU_H_

#include "GameState.h"
#include "Button.h"

class Menu : public GameState {
private:
    SDL_Surface *background, *button, *onePlayerMessage, *twoPlayerMessage, *title;
    Button onePlayerButton, twoPlayerButton;
public:
    Menu();
    ~Menu();
    void handle_events();
    void do_logic();
    void render();
};


#endif /* MENU_H_ */
