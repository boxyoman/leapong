#include "world.h"


int main(int argc, char **argv){
	
	pWorld w = pWorld(argc, argv);
	w.init();
	
	return 0;
}