#include "Ball.h"
#include <SDL.h>


class Ball {
	static const int height = 50;
	static const int width = 50;

   private: 
	   int xPos, yPos, xDirection, yDirection;
	   SDL_Rect collider;

public:
	Ball::Ball() {
		xPos = 75; yPos = 150;
		xDirection = 0; yDirection = 0;
		collider.w = width;
		collider.h = height;
	}
	void changeDirection(int newX, int newY) {
		xDirection = newX; yDirection = newY;
	}
	void move() {
		xPos += xDirection; yPos += yDirection;
	}
};
