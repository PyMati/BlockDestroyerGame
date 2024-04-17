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

	vector<Block*> gameBlocks;

	void initScreen();
	vector<SDL_Texture*> loadSprites();
	vector<Block*> initBlocks(vector<SDL_Texture*> textures);
	void turnOffGame();
	void manageGameEvent();
	void manageRendering(int fps);

public:
	Game(int windowWidth, int windowHeight);
	void run(int fps);
};