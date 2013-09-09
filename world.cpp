#include "world.h"
#include <math.h>

pWorld::pWorld(int argc, char **argv){
	
}

void pWorld::init(){
	initscr();
	cbreak();
	timeout(10);
	noecho();
	while(1){
		loop();
	}
	
	
	
	endwin();
}


void pWorld::loop(){
	int ch = getch();
	
	refresh();
}

pWorld::~pWorld(){
	
}