#include "world.h"

pWorld::pWorld(int argc, char **argv){
	
}

void pWorld::init(){
	initscr();
	raw();
	printw("Hello");
	refresh();
	getch();
	
	endwin();
}

pWorld::~pWorld(){
	
}