#include <SDL_image.h>
#include <vector>
#include <string>
#include "Game.h"
#include "Screen.h"
#include "Pallete.h"
#include "Block.h"
#include "Ball.h"
#include "TextureManager.h"

#define PALLETE_SPRITE "assets/pallete.png"
#define BLOCK_SPRITE_PREFIX "assets/stage"
#define BALL_SPRITE "assets/ball.png"

#define SECOND_IN_MILISECONDS 1000

#define PALLETE_STARTING_POINT_X 270
#define PALLETE_STARTING_POINT_Y 500
#define PALLETE_SPEED 10

#define BALL_STARTING_POINT_X 295
#define BALL_STARTING_POINT_Y 360
#define BALL_SPEED 5

#define BLOCKS_COLUMNS 28
#define BLOCKS_ROWS 5

#define STARTING_BLOCK_POS_X 20
#define STARTING_BLOCK_POS_Y 60
#define BLOCK_SIZE 20

Game::Game(int windowWidth, int windowHeight): windowW(windowWidth), windowH(windowHeight)
{
	initScreen();
	
	// Vector receives 5 sprites / sprite at index 0 = Pallet / 1 - 3 Blocks | 3 == most destroyed block / 4 = Ball 
	vector<SDL_Texture*> sprites = loadSprites();

	this->pallete = new Pallete(PALLETE_STARTING_POINT_X, PALLETE_STARTING_POINT_Y, PALLETE_SPEED, sprites[0]);
	this->ball = new Ball(BALL_STARTING_POINT_X, BALL_STARTING_POINT_Y, BALL_SPEED, sprites[4]);

	this->gameBlocks = initBlocks(sprites);
}

void Game::initScreen() {
	this->screen = new Screen(this->windowW, this->windowH);
}

vector<SDL_Texture*> Game::loadSprites()
{
	vector<SDL_Texture*> spritesVector;

	// Loading pallete sprite
	SDL_Texture* texture = TextureManager::loadTexture(PALLETE_SPRITE, this->screen->getRenderer());
	spritesVector.push_back(texture);
	
	// Loading blocks sprites
	for (int i = 1; i < 4; i++) {
		std::string blockSpritePath = BLOCK_SPRITE_PREFIX;
		blockSpritePath += std::to_string(i) + ".png";
		texture = TextureManager::loadTexture(blockSpritePath, this->screen->getRenderer());
		spritesVector.push_back(texture);
	}

	// Loading ball sprite
	texture = TextureManager::loadTexture(BALL_SPRITE, this->screen->getRenderer());
	spritesVector.push_back(texture);

	return spritesVector;
}

vector<Block*> Game::initBlocks(vector<SDL_Texture*> textures)
{
	// Adding block textures to vector
	vector<SDL_Texture*> blockTextures;
	blockTextures.push_back(textures[1]);
	blockTextures.push_back(textures[2]);
	blockTextures.push_back(textures[3]);

	vector<Block*> blocks;
	Block* newBlock;
	int x;
	int y;


	for (int col_index = 0; col_index < BLOCKS_COLUMNS; col_index++) {
		for (int row_index = 0; row_index < BLOCKS_ROWS; row_index++) {
			x = col_index * BLOCK_SIZE + STARTING_BLOCK_POS_X;
			y = row_index * BLOCK_SIZE + STARTING_BLOCK_POS_Y;
			newBlock = new Block(x, y, blockTextures);
			blocks.push_back(newBlock);
		}
	}

	return blocks;
}

void Game::run(int fps)
{
	while (shouldRun) {
		this->manageGameEvent();
		this->ball->move();
		this->ball->checkCollisionWithPallete(this->pallete->getDest());
		this->manageRendering(fps);
	}

	this->screen->destroy();

	IMG_Quit();
	SDL_Quit();
}

void Game::turnOffGame()
{
	this->shouldRun = false;
}

void Game::manageGameEvent()
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		switch (event.type)
		{
		case SDL_QUIT:
			this->turnOffGame();
		case SDL_KEYDOWN:
			switch (event.key.keysym.scancode)
			{
			case SDL_SCANCODE_LEFT:
				pallete->moveLeft();
				break;
			case SDL_SCANCODE_RIGHT:
				pallete->moveRight();
				break;
			default:
				break;
			}
		default:
			break;
		}
	}
}

void Game::manageRendering(int fps)
{
	SDL_RenderClear(screen->getRenderer());

	// Drawing game objects
	SDL_RenderCopy(screen->getRenderer(), this->pallete->getTexture(), NULL, pallete->getDest());
	SDL_RenderCopy(screen->getRenderer(), this->ball->getTexture(), NULL, this->ball->getDest());
	for (int i = 0; i < this->gameBlocks.size(); i++) {
		SDL_RenderCopy(screen->getRenderer(), gameBlocks[i]->getTexture(), NULL, gameBlocks[i]->getDest());
	}

	SDL_RenderPresent(screen->getRenderer());
	SDL_Delay(SECOND_IN_MILISECONDS / fps);
}
