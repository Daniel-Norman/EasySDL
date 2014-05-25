#include "SDL.h"
#include "SDLWindow.h"
#include "SDLRect.h"
#include <cstdlib>
#include <thread>
#include <chrono>

//Demo for testing custom easy SDL Objects
int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}

	int msSleep = 1000000 / 120;
	bool leftPressed = false, rightPressed = false, upPressed = false, downPressed = false;

	SDLWindow window("Test", 640, 480);
	SDLRect square(100, 100, 50, 50, 0, 0, 150, 255, true);
	window.addObject(square);

	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type){
			case SDL_QUIT:
				return 1;
			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_LEFT) leftPressed = true;
				if (event.key.keysym.sym == SDLK_RIGHT) rightPressed = true;
				if (event.key.keysym.sym == SDLK_UP) upPressed = true;
				if (event.key.keysym.sym == SDLK_DOWN) downPressed = true;
				break;
			case SDL_KEYUP:
				if (event.key.keysym.sym == SDLK_LEFT) leftPressed = false;
				if (event.key.keysym.sym == SDLK_RIGHT) rightPressed = false;
				if (event.key.keysym.sym == SDLK_UP) upPressed = false;
				if (event.key.keysym.sym == SDLK_DOWN) downPressed = false;
				break;
			}

		}



		if (leftPressed) square.x -= upPressed || downPressed ? 1.4142 : 2;
		if (rightPressed) square.x += upPressed || downPressed ? 1.4142 : 2;
		if (upPressed) square.y -= leftPressed || rightPressed ? 1.4142 : 2;
		if (downPressed) square.y += leftPressed || rightPressed ? 1.4142 : 2;

		square.red() += 1;


		window.render(); 
		this_thread::sleep_for(chrono::microseconds(msSleep));
	}

	return 0;
}