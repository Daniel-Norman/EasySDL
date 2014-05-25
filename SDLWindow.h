#pragma once
#include "SDL.h"
#include "SDLObject.h"
#include <vector>
#include <Windows.h>

using namespace std;

class SDLWindow
{
public:
	SDLWindow(char*, int, int, Uint8 = 255, Uint8 = 255, Uint8 = 255);
	void render();
	void setColor(Uint8, Uint8, Uint8, Uint8 = 255);
	void setBackgroundColor(Uint8, Uint8, Uint8);
	void drawLine(int, int, int, int);
	void drawRect(int, int, int, int);
	void fillRect(int, int, int, int);
	void addObject(SDLObject&);
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Uint8 bgR, bgG, bgB;
	vector<SDLObject*> objectList;
};

//Creates a window. Default background color white
SDLWindow::SDLWindow(char* title, int w, int h, Uint8 r, Uint8 g, Uint8 b) : bgR(r), bgG(g), bgB(b)
{
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
	renderer = SDL_CreateRenderer(window, -1, 0);
	setColor(bgR, bgG, bgB);
	SDL_RenderClear(renderer);
}

void SDLWindow::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

void SDLWindow::setBackgroundColor(Uint8 r, Uint8 g, Uint8 b)
{
	bgR = r;
	bgG = g;
	bgB = b;
}

void SDLWindow::render()
{
	setColor(bgR, bgG, bgB);
	SDL_RenderClear(renderer); //Render the background
	
	for (vector<SDLObject*>::iterator it = objectList.begin(); it != objectList.end(); ++it)
	{
		(*it)->render(renderer);
	}

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

void SDLWindow::addObject(SDLObject& obj)
{
	objectList.push_back(&obj);
}