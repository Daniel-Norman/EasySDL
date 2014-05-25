#pragma once
#include "SDL.h"
#include "SDLObject.h"

class SDLRect : public SDLObject
{
public:
	SDLRect(double, double, double = 0, double = 0, Uint8 = 0, Uint8 = 0, Uint8 = 0, Uint8 = 255, bool = false);
	void render(SDL_Renderer*);
	void setWidth(double);
	void setHeight(double);

	double width, height;
	Uint8& red() { return fgR; }
	Uint8& green() { return fgG; }
	Uint8& blue() { return fgB; }
	Uint8& alpha() { return fgA; }
private:
	Uint8 fgR, fgG, fgB, fgA;
	bool filled;
	SDL_Rect rect;
};

//Creates a SDL Rectangle. Default position: (0,0), color: black, filled: false
SDLRect::SDLRect(double w, double h, double x, double y, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool f) : SDLObject(x, y), width(w), height(h), fgR(r), fgG(g), fgB(b), fgA(a), filled(f)
{
	rect = { (int) this->x, (int) this->y, (int)width, (int)height };
}


void SDLRect::render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, fgR, fgG, fgB, fgA);
	rect.x = (int) this->x;
	rect.y = (int) this->y;

	if (filled) SDL_RenderFillRect(renderer, &rect);
	else SDL_RenderDrawRect(renderer, &rect);
}


void SDLRect::setWidth(double w)
{
	width = w;
	rect.w = (int) width;
}

void SDLRect::setHeight(double h)
{
	height = h;
	rect.h = (int) height;
}