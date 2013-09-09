#include "world.h"
#include <math.h>
#include <time.h>

pWorld::pWorld(int argc, char **argv){
	
}

void pWorld::init(){
	//initializing 
	initscr();
	cbreak();
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
			endwin();
			exit(0);
		}
	}
	
	getInputs();
	
	//Draw the paddles
	for(int i = 0; i<2; i++){
		attron(COLOR_PAIR(i+1));
		for(int j=0; j<player[i]->width; j++){
			mvprintw((int)round(player[i]->pos.y)-(player[i]->width/2)+j, (int)round(player[i]->pos.x), " ");
		}
		attroff(COLOR_PAIR(i+1));
	}
	
	
	for(int i=0; i<2; i++){
		player[i]->update();
	}
	
	mvprintw(col-1,0, "%f", eTime);
	
	//End logic here
	refresh();
}

void pWorld::getInputs(){
	if(controller.isConnected()){
		Frame frame = controller.frame();
		
		float rightPalmY = frame.hands().rightmost().palmPosition().y;
		float leftPalmY = frame.hands().leftmost().palmPosition().y;
		
		
		
		player[1]->pos.y = (float)col - (float)col/150.0*(rightPalmY-100);
		
		mvprintw(col-2,0, "%f", (float)col/150.0*(rightPalmY-100));
		
	}
}

pWorld::~pWorld(){
	delete player[1];
	delete player[2];
	delete ball;
}