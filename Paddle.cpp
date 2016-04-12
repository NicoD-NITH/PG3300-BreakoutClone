#include "Paddle.h"
//#include <SDL.h>

	Paddle::Paddle() {
		height;
		width;
		xPos = 250;
		yPos = 50;
		/*SDL_Rect collider;
		collider.x = xPos;
		collider.y = yPos;
		collider.h = height;
		collider.w = width;*/
	}

	void Paddle::controlLeft() {
		xDirection -= velocity;
	}
	void Paddle::controlRight() {
		xDirection += velocity;
	}

	void Paddle::move() {
		xPos += xDirection;
	}
