#include "player.h"
#include "world.h"

pPlayer::pPlayer(pWorld *world, pLR lr){
	width = 9;
	this->world = world;
	pos.y = world->col/2.0; //position in the middle of the page
	
	pos.x = (lr==pLeft)? 0.0:world->row-1.0;
}

void pPlayer::update(){
	vel += force * world->eTime + vel * world->eTime *-1.0;
	pos += vel * world->eTime;
}