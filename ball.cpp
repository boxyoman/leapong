#include "ball.h"
#include "world.h"
#include "player.h"

pBall::pBall(pWorld* world){
	this->world = world;
	
	pos.x = world->row/2;
	pos.y = world->col/2;
	
	vel.x = -6;
	vel.y = .2;
}

void pBall::update(){
	pos += vel*world->eTime;
	if(pos.y<0){
		pos.y=0;
		vel.y = vel.y * -1.0;
	}
	if(pos.y>world->col-1){
		pos.y=world->col-1;
		vel.y = vel.y * -1.0;
	}
}

void pBall::draw(){
	mvprintw(round(pos.y), round(pos.x), " ");
	mvprintw(round(pos.y), round(pos.x+.5), " ");
	mvprintw(round(pos.y), round(pos.x-.5), " ");
	
}

void pBall::bounce(pPlayer *player){
	float mag = vel.mag()*1.05;
	vel.x = vel.x*-1.1;
	vel.y += player->vel.y*0.1;
	vel = vel.unit()*mag;
}