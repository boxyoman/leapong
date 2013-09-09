#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "vector.h"

class pWorld;

enum pLR{
	pLeft,
	pRight
};

class pPlayer{
	public:
		pPlayer(pWorld* world, pLR);
		int colour;
		int width;
		pVector force;
		pVector pos;
		pVector vel;
		void update();
		void draw();
	private:
		pWorld* world;
};

#endif