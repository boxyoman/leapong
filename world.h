#ifndef _WORLD_H_
#define _WORLD_H_

#include "Leap.h"
#include "LeapMath.h"
#include "ncurses.h"
#include "player.h"
#include "ball.h"

using namespace Leap;

class pPlayer;

class pWorld{
	public:
		pWorld(int argc, char **argv);
		void init();
		float eTime;						//Time from last update
		float col;
		float row;
		~pWorld();
	private:
		
		time_t lastClock;
		
		void cleanup();
		
		Controller controller;
		void loop();
		void getLeapInputs();
		pPlayer *player[2];
		pBall *ball;
};

#endif