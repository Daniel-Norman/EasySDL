#pragma once
#include "SDL.h"
#include "SDLObject.h"
#include <SDL_image.h>

using namespace std;

class SDLImage : public SDLObject
{
public:
	SDLImage(char*, double = 0, double = 0);
	void render(SDL_Renderer*);
private:
	SDL_Surface* image;
	SDL_Texture* texture = NULL;
	SDL_Rect rect;
	char* fileName;
};

SDLImage::SDLImage(char* file, double x, double y) : SDLObject(x, y), fileName(file)
{
	image = IMG_Load(file);
	if (image != NULL) rect = { (int) x, (int) y, (int) image->w, (int) image->h };
}

void SDLImage::render(SDL_Renderer* renderer)
{
	if (texture == NULL)
	{
		texture = SDL_CreateTextureFromSurface(renderer, image);
	}

	rect.x = (int) x;
	rect.y = (int) y;
	
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}