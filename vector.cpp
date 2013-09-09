#include "vector.h"

pVector::pVector(){
	this->x = 0; this->y = 0;
}

pVector::pVector(float x, float y){
	this->x = x; this->y = y;
}

pVector pVector::operator + (pVector v){
	return pVector(this->x+v.x, this->y+v.y);
}

void pVector::operator += (pVector v){
	this->x+=v.x; this->y+=v.y;
}

pVector pVector::operator - (pVector v){
	return pVector(this->x-v.x, this->y-v.y);
}

pVector pVector::operator * (float a){
	return pVector(this->x*a, this->y*a);
}

float pVector::operator * (pVector v){
	return this->x*v.x + this->y*v.y;
}