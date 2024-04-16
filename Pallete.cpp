#include "Pallete.h"
#include <iostream>

#define PALLETEW 60
#define PALLETEH 20
#define SPEED 10

#define RIGHT_BOUNDARY 540
#define LEFT_BOUNDARY 0

Pallete::Pallete(int x, int y, int speed, SDL_Texture* texture) : palleteSpeed(speed), palleteTexture(texture), GameObject(x, y)
{
	SDL_QueryTexture(this->palleteTexture, NULL, NULL, &rect.w, &rect.h);
	rect.w = PALLETEW;
	rect.h = PALLETEH;
	rect.x = this->x;
	rect.y = this->y;
}

SDL_Texture* Pallete::getTexture()
{
	return this->palleteTexture;
}

SDL_Rect* Pallete::getDest()
{
	return &this->rect;
}

void Pallete::moveRight()
{
	if (canMove(this->palleteSpeed)) {
		this->rect.x += this->palleteSpeed;
	}
}

void Pallete::moveLeft()
{
	if (canMove(-this->palleteSpeed)) {
		this->rect.x -= this->palleteSpeed;
	}
}

bool Pallete::canMove(int deltaX)
{
	if (this->rect.x + deltaX <= LEFT_BOUNDARY || this->rect.x + deltaX >= RIGHT_BOUNDARY) {
		return false;
	}
	return true;
}
