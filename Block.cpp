#include "Block.h"
#include <vector>
#include <SDL_image.h>
#include <SDL.h>

#define STARTING_BLOCK_HEALTH 3
#define POINTS_FOR_BLOCK 100
#define BLOCK_SIZE 20
#define STARTING_TEXTURE_INDEX 0

Block::Block(int x, int y, std::vector<SDL_Texture*> textures):blockTextures(textures), health(STARTING_BLOCK_HEALTH), pointsForBlock(POINTS_FOR_BLOCK), isDestroyed(false),textureIndex(STARTING_TEXTURE_INDEX), GameObject(x, y)
{
	SDL_QueryTexture(this->getTexture() , NULL, NULL, &rect.w, &rect.h);
	this->rect.w = BLOCK_SIZE;
	this->rect.h = BLOCK_SIZE;
	this->rect.x = this->x;
	this->rect.y = this->y;
}

SDL_Texture* Block::getTexture()
{
	return this->blockTextures[this->textureIndex];
}

SDL_Rect* Block::getDest()
{
	return &this->rect;
}
