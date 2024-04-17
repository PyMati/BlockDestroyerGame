#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "GameObject.h"

class Ball: public GameObject
{
	int upDownDirection;
	int leftRightDirection;
	int ballSpeed;
	SDL_Texture* ballTexture;
	SDL_Rect rect;

public:
	Ball(int x, int y, int speed, SDL_Texture* texture);
	SDL_Texture* getTexture() override;
	SDL_Rect* getDest() override;
	void changeVerticalDirection();
	void changeHorizotalDirection();
	bool shouldChangeVerticalDirection();
	bool shouldChangeHorizotalDirection();
	void move();
	int generateRandomDirection();
	void checkCollisionWithPallete(SDL_Rect* palleteRect);
};

