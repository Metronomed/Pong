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