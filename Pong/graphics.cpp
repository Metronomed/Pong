#include "graphics.h"

#include <SDL.h>
#include "game.h"
#include <stdio.h>

const int gameBPP = 32;

//initializes screen
Graphics::Graphics() {
	screen_ = SDL_SetVideoMode(Game::gameScreenWidth,
		Game::gameScreenHeight,
		gameBPP, 0 /*no flags*/);
	if (screen_ == NULL) {
		printf("Could not initialize screen");
	}
}

Graphics::~Graphics() {
	SDL_FreeSurface(screen_);
}

//blits the source graphic to the screen
void Graphics::blitScreen(SDL_Surface* source,
	SDL_Rect* source_rect,
	SDL_Rect* destination_rect) {
	if (SDL_BlitSurface(source, source_rect, screen_, destination_rect) == -1) {
		printf("Could not blit to screen");
	}
}

//Load an image from a bmp to store as a surface
SDL_Surface* Graphics::loadImage(const std::string& filepath, bool black_transparency) {
	SDL_Surface* loadedImage = NULL;
	SDL_Surface* optimizedImage = NULL;
	loadedImage = SDL_LoadBMP(filepath.c_str());

	if (loadedImage != NULL) {
		//convert it to same format as screen for better blitting
		optimizedImage = SDL_DisplayFormat(loadedImage);
		SDL_FreeSurface(loadedImage);

		//do transparency
		if (black_transparency == true) {
			Uint32 black = SDL_MapRGB(screen_->format, 0, 0, 0);
			SDL_SetColorKey(screen_, SDL_SRCCOLORKEY, black);
		}
	}
	else {
		printf("Could not load file at %s", filepath);
	}
	return optimizedImage;
}

//clears screen to black
void Graphics::clear() {
	Uint32 black = SDL_MapRGB(screen_->format, 0, 0, 0);
	if (SDL_FillRect(screen_, NULL, black) == -1) {
		printf("Could not clear the screen");
	}
}

//flip screen to the other buffer
void Graphics::flip() {
	if (SDL_Flip(screen_) == -1) {
		printf("Could not flip screen");
	}
}