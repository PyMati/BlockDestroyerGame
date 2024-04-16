#pragma once
#include <vector>
#include "Screen.h"
#include "Pallete.h"
#include "Block.h"
#include "TextureManager.h"
#include "Ball.h"

using namespace std;

class Game {
private:
	int windowW;
	int windowH;
	bool shouldRun = true;

	Screen* screen;
	Pallete* pallete;
	Ball* ball;



public:
	Game(int windowWidth, int windowHeight);
	void initScreen();
	vector<SDL_Texture*> loadSprites();
	void run(int fps);
	void turnOffGame();
	void manageGameEvent();
	void manageRendering(int fps);
};