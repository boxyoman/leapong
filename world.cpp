#include "world.h"
#include <math.h>

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
	
	while(1){
		loop();
	}
	
	
}

void pWorld::loop(){
	int ch = getch();
	//erase();
	//logic goes here
	if (ch != ERR){
		if(ch == 113){ //if ch == "q"
			endwin();
			exit(0);
		}
	}
	
	
	/*mvprintw(0,0,"(%d, %d)", (int)col, (int)row);
	mvprintw(1,0,"player 1 position: (%d, %d)", (int)round(player[0]->pos.x), (int)round(player[0]->pos.y));
	mvprintw(2,0,"player 2 position: (%d, %d)", (int)round(player[1]->pos.x), (int)round(player[1]->pos.y));*/
	
	//Draw the paddles
	for(int i = 0; i<2; i++){
		attron(COLOR_PAIR(i+1));
		for(int j=0; j<player[i]->width; j++){
			mvprintw((int)round(player[i]->pos.y)-(player[i]->width/2)+j, (int)round(player[i]->pos.x), " ");
		}
		attroff(COLOR_PAIR(i+1));
	}
	
	
	
	//End logic here
	refresh();
}

pWorld::~pWorld(){
	delete player[1];
	delete player[2];
	delete ball;
}