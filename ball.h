#ifndef _BALL_H_
#define _BALL_H_

#include "vector.h"

class pWorld;

class pBall{
	public:
		pBall(pWorld *world);
		pVector pos;
		pVector vel;
		void update();
		void draw();
		
	private:
		pWorld *world;
};

#endif