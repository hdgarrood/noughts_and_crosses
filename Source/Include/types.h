/*
 * types.h
 *
 *  Created on: Feb 10, 2012
 *      Author: Harry
 */

#ifndef TYPES_H_
#define TYPES_H_

struct tMyMouseEvent {
	bool pressed;
	bool released;
	int x;
	int y;
	void reset() {
		x = 0;
		y = 0;
		pressed = false;
		released = false;
	}
};


#endif /* TYPES_H_ */
