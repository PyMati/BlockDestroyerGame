#include "Screen.h"
#include <SDL.h>
#include <SDL_image.h>

#define PaletteGameTitle "Pallete Game By Mateusz Cieslinski"

Screen::Screen(int _width, int _height) : width(_width), height(_height) {
	this->window = SDL_CreateWindow(PaletteGameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _width, _height, 0);
	this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Window* Screen::getWindow()
{
	return this->window;
}

SDL_Renderer* Screen::getRenderer()
{
	return this->renderer;
}

void Screen::destroy()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
}

void Screen::refresh()
{
	SDL_RenderClear(this->renderer);
}
