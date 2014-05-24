#include "SDL.h"
#include "SDLWindow.h"
#include <cstdlib>

int main(int argc, char* argv[]) {

	if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return 1;
	}

	SDLWindow window("Pathfinding", 640, 480);





	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				return 0;
		}

		window.setColor(rand() % 256, rand() % 256, rand() % 256);
		window.fillRect(rand() % 640, rand() % 480, rand() % 100, rand() % 100);


		window.render();
	}

	return 0;
}
