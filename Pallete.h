#pragma once
#include "GameObject.h"
#include <SDL_image.h>
class Pallete: public GameObject
{
	SDL_Texture* palleteTexture;
	SDL_Rect rect;
	int palleteSpeed;

public:
	Pallete(int x, int y, int speed, SDL_Texture* texture);
	SDL_Texture* getTexture() override;
	SDL_Rect* getDest() override;
	void moveRight();
	void moveLeft();
	bool canMove(int deltaX);
};

