#include "TextureManager.h"
#include <SDL_image.h>
#include <iostream>



SDL_Texture* TextureManager::loadTexture(std::string path, SDL_Renderer* renderer)
{
    SDL_Surface* surface = IMG_Load(path.c_str());
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (texture == NULL) {
        std::cout << "An error occured while loading sprites from " << path << std::endl;
        std::cout << "Aborting program..." << std::endl;
        abort();
    }
    SDL_FreeSurface(surface);
    return texture;
}
