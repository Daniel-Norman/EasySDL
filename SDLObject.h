#pragma once
#include "SDL.h"

class SDLObject
{
public:
	SDLObject(double = 0, double = 0);
	virtual void render(SDL_Renderer*) = 0;
	void setPosition(double, double);
	double x, y;
};

SDLObject::SDLObject(double x, double y) : x(x), y(y) {}

void SDLObject::setPosition(double x, double y)
{
	this->x = x;
	this->y = y;
}