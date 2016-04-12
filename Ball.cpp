#include "Ball.h"
//#include <SDL_rect.h>


Ball::Ball() {
	xPos = 75; yPos = 150;
	xDirection = 0; yDirection = 0;
	/*SDL_Rect collider;
	collider.w = width;
	collider.h = height;
	collider.x = xPos;
	collider.y = yPos;*/
}
	void Ball::changeDirection(int newX, int newY) {
		xDirection = newX; yDirection = newY;
	}
	void Ball::move() {
		xPos += xDirection; yPos += yDirection;
	}
