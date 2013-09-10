#ifndef _VECTOR_H_
#define _VECTOR_H_

class pVector{
	public:
		float x,y;
		pVector();
		pVector(float x, float y);
		pVector operator + (pVector);
		void operator += (pVector);
		pVector operator - (pVector);
		pVector operator * (float);
		float operator * (pVector);
		float mag();
		pVector unit();
};

#endif