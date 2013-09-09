#include "world.h"
#include <math.h>
#include <time.h>

pWorld::pWorld(int argc, char **argv){
	
}

void pWorld::init(){
	//initializing 
	initscr();
	cbreak();
	curs_set(0);
	if(has_colors() == FALSE){
		endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
	start_color();
	
	timeout(10);
	noecho();
	
	
	int row, col;
	getmaxyx(stdscr, col, row);	
	this->col = (float)col;
	this->row = (float)row;
	
	init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_WHITE);
	init_pair(3, COLOR_RED, COLOR_RED);
	
	player[0] = new pPlayer(this, pLeft);
	player[1] = new pPlayer(this, pRight);
	ball = new pBall(this);
	
	lastClock = clock();
	
	while(1){
		loop();
	}
	
	
}

void pWorld::loop(){
	int ch = getch();
	
	eTime = (float)(clock()-lastClock)/CLOCKS_PER_SEC*100;
	lastClock = clock();
	
	erase();
	//logic goes here
	if (ch != ERR){
		if(ch == 113){ //if ch == "q"
			cleanup();
			endwin();
			exit(0);
		}
	}
	
	getLeapInputs();
	
	//drawBall
	attron(COLOR_PAIR(3));
	ball->draw();
	attroff(COLOR_PAIR(3));
	
	//Draw the paddles
	for(int i = 0; i<2; i++){
		attron(COLOR_PAIR(i+1));
		for(int j=0; j<player[i]->width; j++){
			mvprintw((int)round(player[i]->pos.y)-(player[i]->width/2)+j, (int)round(player[i]->pos.x), " ");
		}
		attroff(COLOR_PAIR(i+1));
	}
	
	//update paggle position based on the force provided by leap
	for(int i=0; i<2; i++){
		player[i]->update();
	}
	ball->update();
	mvprintw(col-1, 0, "%f %d", ball->pos.x, row);
	if(ball->pos.x<1.3){
		if(player[0]->pos.y+player[0]->width/2 > ball->pos.y && player[0]->pos.y-player[0]->width/2 < ball->pos.y){
			ball->vel = ball->vel * -1.0;
		}
	}
	if(ball->pos.x>row-1.3){
		if(player[1]->pos.y+player[1]->width/2 > ball->pos.y && player[1]->pos.y-player[1]->width/2 < ball->pos.y){
			ball->vel = ball->vel * -1.0;
		}
	}
	
	//End logic here
	refresh();
}

void pWorld::getLeapInputs(){
	if(controller.isConnected()){
		Frame frame = controller.frame();
		
		float rightPalmY = frame.hands().rightmost().palmPosition().y;
		float leftPalmY = frame.hands().leftmost().palmPosition().y;
		
		player[0]->force.y = ((float)col - (float)col/150.0*( leftPalmY-100)) - player[0]->pos.y;
		player[1]->force.y = ((float)col - (float)col/150.0*(rightPalmY-100)) - player[1]->pos.y;
		
	}
}

void pWorld::cleanup(){
	for(int i=0; i<2; i++){
		if(player[i]!=NULL){
			delete player[i];
			player[i] = NULL;
		}
	}
	if(ball != NULL){
		delete ball;
		ball = NULL;
	}
}

pWorld::~pWorld(){
	cleanup();
}