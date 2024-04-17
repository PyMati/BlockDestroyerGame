#pragma once
#include "GameObject.h"
#include <vector>
#include <SDL_image.h>
#include <SDL.h>


class Block: public GameObject
{
	std::vector <SDL_Texture*> blockTextures;
	int health;
	int pointsForBlock;
	bool isDestroyed;
	int textureIndex;

	SDL_Rect rect;

public:
	Block(int x, int y, std::vector <SDL_Texture*> textures);
	SDL_Texture* getTexture() override;
	SDL_Rect* getDest() override;
};

