#ifndef _BALL_H_
#define _BALL_H_

#include "vector.h"

class pWorld;
class pPlayer;

class pBall{
	public:
		pBall(pWorld *world);
		pVector pos;
		pVector vel;
		void update();
		void draw();
		void bounce(pPlayer*);
		
	private:
		pWorld *world;
};

#endif