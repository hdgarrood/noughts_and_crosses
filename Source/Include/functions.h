/*
 * functions.h
 *
 *  Created on: Feb 9, 2012
 *      Author: Harry
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "SDL/SDL.h"
#include <string>

SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination);

#endif /* FUNCTIONS_H_ */
