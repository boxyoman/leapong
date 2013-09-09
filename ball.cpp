#include "ball.h"
#include "world.h"

pBall::pBall(pWorld* world){
	this->world = world;
	size = 2;
	
	pos.x = world->col/2;
	pos.y = world->row/2;
}

void pBall::update(){
	pos += vel*world->eTime;
}

