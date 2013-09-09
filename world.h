#ifndef _WORLD_H_
#define _WORLD_H_

#include "Leap.h"
#include "LeapMath.h"


class pWorld{
	public:
		pWorld(int argc, char **argv);
		static void loop();
		void init();
};

#endif