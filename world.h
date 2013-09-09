#ifndef _WORLD_H_
#define _WORLD_H_

#include "Leap.h"
#include "LeapMath.h"
#include "ncurses.h"

using namespace Leap;

class pWorld{
	public:
		pWorld(int argc, char **argv);
		void init();
		void loop();
		Controller controller;
		
		
		~pWorld();
		
};

#endif