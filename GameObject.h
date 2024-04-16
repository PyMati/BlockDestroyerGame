#pragma once
#include "SDL.h"
#include "SDL_image.h"

class GameObject {
public:
	int x;
	int y;
	GameObject(int _x, int _y);

	virtual SDL_Texture* getTexture() { return nullptr; }
	virtual SDL_Rect* getDest() { return nullptr; }
};