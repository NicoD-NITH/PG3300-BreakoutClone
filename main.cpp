#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include "paddle.h"
#include "Ball.h"


const int S_Width = 640;
const int S_Height = 480;

SDL_Window* window = NULL;
SDL_Renderer* renderer;

SDL_Surface* screenSurface = NULL;

bool started();

bool loadResources();

void quit();

bool started() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not start. SDL_Error: %s\n", SDL_GetError());
		return success = false;
	}
	else {
		window = SDL_CreateWindow("LOLWINDOW", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, S_Width, S_Height, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Could not create window. SDL_Error: %s\n,", SDL_GetError());
			return success = false;
		}
		else {
			screenSurface = SDL_GetWindowSurface(window);

			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(window);
		}
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (renderer == NULL) {
			printf("OH SNAP, NO RENDERER!");
			return success = false;
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
	}
	return success = true;
}

bool loadResources() {
	bool success = true;;

	return success;
}

void quit() {
	SDL_DestroyWindow(window);

	SDL_Quit();
}


int main(int argc, int **argv) {
	if (!started()) {
		quit();
		return 1;
	}
	if (!loadResources()) {
		quit();
		return 1;
	}
	/*Initialisere spillobjekter
	 * Ball ball;*/
	 Paddle paddle;
	
	 //loop start
	bool gameActive = true;
    while(gameActive) {
		SDL_Event e;
		if(SDL_PollEvent(&e)) {
			if (e.type = SDL_KEYDOWN && e.key.repeat == 0) {
				switch (e.key.keysym.sym) {
				case SDLK_RIGHT: paddle.controlRight();
				case SDLK_LEFT: paddle.controlLeft();
				}
			}
			if(e.type == SDL_QUIT) {
				gameActive = false;
			}
			
		}
		/*showBricks();
		ball.move();
		paddle.move();
		ball.show();
		paddle.show();*/
	}
	if (!gameActive) {
		quit();
		return 0;
	}
}
	 

bool collision(SDL_Rect a, SDL_Rect b) {
	int aLeft, bLeft;
	int aRight, bRight;
	int aTop, bTop;
	int aBottom, bBottom;

	//rect a sider
	aLeft = a.x;
	aRight = a.x +a.w;
	aTop = a.y;
	aBottom = a.y + a.h;
	
	//rect b sider
	bLeft = b.x;
	bRight = b.x + b.w;
	bTop = b.y;
	bBottom = b.y + b.h;

	if (aBottom <= bTop) {
		return false;
	}
	if(aTop >= bBottom) {
		return false;
	}
	if (aLeft >= bRight) {
		return false;
	}
	if (aRight <= bLeft) {
		return false;
	}
	return true;
}


