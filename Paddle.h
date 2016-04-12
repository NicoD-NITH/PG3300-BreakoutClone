#ifndef Paddle_H
#define Paddle_H

class Paddle {
public:
	Paddle::Paddle();
	void move();
	void controlLeft();
	void controlRight();
public:
	int xPos, yPos, xDirection;
	int velocity = 10;
	static const int height = 50;
	static const int width = 200;
	
};

#endif