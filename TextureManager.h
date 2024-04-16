#pragma once
#include <string>
#include <SDL_image.h>


class TextureManager
{
public:
	static SDL_Texture* loadTexture(std::string path, SDL_Renderer* renderer);
};

