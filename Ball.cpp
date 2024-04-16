#include "Ball.h"
#include <iostream>

#define BALL_SIZE 10

#define UP_RIGHT_BOUNDARY 600
#define LEFT_DOWN_BOUNDARY 0

#define MAX 100
#define MIN 0

Ball::Ball(int x, int y, int speed, SDL_Texture* texture) : ballSpeed(speed), ballTexture(texture), GameObject(x, y)
{
	this->leftRightDirection = this->generateRandomDirection();
	this->upDownDirection = this->generateRandomDirection();
	SDL_QueryTexture(this->ballTexture, NULL, NULL, &rect.w, &rect.h);
	rect.w = BALL_SIZE;
	rect.h = BALL_SIZE;
	rect.x = this->x;
	rect.y = this->y;
}


SDL_Texture* Ball::getTexture()
{
	return this->ballTexture;
}

SDL_Rect* Ball::getDest()
{
	return &this->rect;
}

void Ball::changeVerticalDirection()
{
	this->upDownDirection *= -1;
}

void Ball::changeHorizotalDirection()
{
	this->leftRightDirection *= -1;
}

bool Ball::shouldChangeVerticalDirection()
{
	if (this->rect.y >= UP_RIGHT_BOUNDARY || this->rect.y <= LEFT_DOWN_BOUNDARY) {
		//this->leftRightDirection = this->generateRandomDirection();
		this->leftRightDirection *=  -1;
		return true;
	}
	return false;
}

bool Ball::shouldChangeHorizotalDirection()
{
	if (this->rect.x <= LEFT_DOWN_BOUNDARY || this->rect.x >= UP_RIGHT_BOUNDARY) {
		return true;
	}
	return false;
}

void Ball::move()
{
	if (shouldChangeHorizotalDirection()) {
		this->changeHorizotalDirection();
	}

	if (shouldChangeVerticalDirection()) {
		this->changeVerticalDirection();
	}


	this->rect.x += (this->ballSpeed * this->leftRightDirection);
	this->rect.y += (this->ballSpeed * this->upDownDirection);

	std::cout << this->rect.x << "||" << this->rect.y << std::endl;
}

int Ball::generateRandomDirection()
{
	int randomResult = rand() % (MAX - MIN + 1) + MIN;
	if (randomResult >= 50) {
		randomResult = 1;
	}
	else {
		randomResult = -1;
	}
	return randomResult;
}

void Ball::checkCollision(SDL_Rect* palleteRect)
{
	// Pallete width = 60 pallete height = 20
	// Hitting pallete from up and down
	if (this->rect.x >= palleteRect->x && this->rect.x <= palleteRect->x + 60) {
		if (this->rect.y == palleteRect->y) {
			this->rect.y = palleteRect->y - 10;
			this->changeVerticalDirection();
		}
		else if (this->rect.y == palleteRect->y + 20) {
			this->rect.y = palleteRect->y + 25;
			this->changeVerticalDirection();
		}
	}
	// Hitting pallete from sides
	else if ((this->rect.y + BALL_SIZE >= palleteRect->y) && (this->rect.y <= palleteRect->y + 20)) {
		if (this->rect.x + BALL_SIZE == palleteRect->x) {
			this->rect.x = palleteRect->x - BALL_SIZE;
			this->changeHorizotalDirection();
		}
		else if (this->rect.x - BALL_SIZE == palleteRect->x + 60) {
			this->rect.x = palleteRect->x + 65;
			this->changeHorizotalDirection();
		}
	}
}

