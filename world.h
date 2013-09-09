#ifndef _WORLD_H_
#define _WORLD_H_

#include "Leap.h"
#include "LeapMath.h"
#include "pListener.h"
#include "ncurses.h"

using namespace Leap;

class pWorld{
	public:
		pWorld(int argc, char **argv);
		void loop();
		void init();
		
		pListener listener;
		Controller controller;
		
		
};

#endif