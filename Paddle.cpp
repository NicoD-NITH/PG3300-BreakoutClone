#include "Paddle.h"
#include <SDL.h>


class Paddle {
	int xPos, yPos, xDirection;
	int velocity = 10;
	static const int height = 50; 
	static const int width = 200;

	SDL_Rect collider;
public:
	Paddle::Paddle() {
		xPos = 100; yPos = 100;
		xDirection = 0;
		collider.w = width;
		collider.h = height;
	}

	void control(SDL_Event& e) {
		if (e.type = SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_RIGHT: xDirection += velocity; 
				break;
			case SDLK_LEFT: xDirection -= velocity; 
				break;
			}
		}
		else if (e.type = SDL_KEYDOWN && e.key.repeat == 0) {
			switch (e.key.keysym.sym) {
			case SDLK_RIGHT: xDirection -= velocity; 
				break;
			case SDLK_LEFT: xDirection += velocity;
				break;
			}
		}
	}

	void move() {
		xPos += xDirection;
	}
};