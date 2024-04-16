#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Screen
{
private:
	int width;
	int height;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Screen(int _width, int _height);
	SDL_Window* getWindow();
	SDL_Renderer* getRenderer();
	void destroy();
	void refresh();
};

