#include "SDL.h"

class SDLWindow
{
public:
	SDLWindow(char*, int, int);
	void render();
	void setColor(Uint8, Uint8, Uint8, Uint8 = 255);
	void drawLine(int, int, int, int);
	void drawRect(int, int, int, int);
	void fillRect(int, int, int, int);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};

SDLWindow::SDLWindow(char* title, int w, int h)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	setColor(255, 255, 255);
	SDL_RenderClear(renderer);
}

void SDLWindow::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDLWindow::render()
{
	SDL_RenderPresent(renderer);
}

void SDLWindow::drawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void SDLWindow::drawRect(int x1, int y1, int x2, int y2)
{
	SDL_Rect r = { x1, y1, x2, y2 };
	SDL_RenderDrawRect(renderer, &r);
}

void SDLWindow::fillRect(int x1, int y1, int x2, int y2)
{
	SDL_Rect r = { x1, y1, x2, y2 };
	SDL_RenderFillRect(renderer, &r);
}