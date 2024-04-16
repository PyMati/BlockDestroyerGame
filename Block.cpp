#include "Block.h"
#include <vector>
#include <SDL_image.h>
#include <SDL.h>

#define STARTING_BLOCK_HEALTH 3
#define POINTS_FOR_BLOCK 100


Block::Block(int x, int y, std::vector<SDL_Texture*> textures):blockTextures(textures), health(STARTING_BLOCK_HEALTH), pointsForBlock(POINTS_FOR_BLOCK), isDestroyed(false), GameObject(x, y)
{
}

SDL_Texture* Block::getTexture()
{
	if (!this->isDestroyed) {
		return nullptr;
	}
}

SDL_Rect* Block::getDest()
{
	return nullptr;
}
