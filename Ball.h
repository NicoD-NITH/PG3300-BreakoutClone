#ifndef Ball_H
#define Ball_H

//#include <SDL.h>

class Ball
{
public:
	Ball::Ball();
	void move();
	void changeDirection(int newX, int newY);

public:
	static const int width = 50;
	static const int height = 50;
	int xPos, yPos, xDirection, yDirection;
	
};

#endif

