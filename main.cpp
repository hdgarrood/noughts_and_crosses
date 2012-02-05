#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include <string>
#include "GameController.h"

int main( int argc, char* args[] ) {
	bool quit = false;
    SDL_Init( SDL_INIT_EVERYTHING );
    TTF_Init();

    Game_Controller controller;
    SDL_Event event;

    while (quit==false) {
    	while (SDL_PollEvent( &event )) {
    		switch (event.type) {
    			case SDL_QUIT:
    				quit = true;
    				break;
    			case SDL_MOUSEBUTTONDOWN:
    				controller.MouseDown(event.button.button, event.button.x, event.button.y);
    				break;
    			case SDL_KEYDOWN:
    				controller.KeyDown(event.key.keysym.sym);
    				break;
    		}

    	}
    }

    SDL_Quit();
    return 0;
}
