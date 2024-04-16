#include <iostream>
#include "Game.h"
#include <SDL.h>
#include <SDL_image.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 600
#define FPS 60
#define INIT_SUCCESS 0

void initSdlLibraries() {

	if (SDL_Init(SDL_INIT_EVERYTHING) != INIT_SUCCESS) {
		std::cout << "Error occured while initializing sdl library...\nAborting..." << std::endl;
		abort();
	};
	IMG_Init(IMG_INIT_PNG);
}

int main(int argc, char* argv[]) {

	initSdlLibraries();

	Game game(WINDOW_WIDTH, WINDOW_HEIGHT);
	game.run(FPS);

	return 1;
}