#ifndef _BALL_H_
#define _BALL_H_

#include "vector.h"

class pWorld;

class pBall{
	public:
		pBall(pWorld *world);
		int size;
		pVector pos;
		pVector vel;
		void update();
		
	private:
		pWorld *world;
};

#endif