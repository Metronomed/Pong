#include "game.h"

#include <SDL.h>

//initialize SDL and start it running
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	runGame();
}

//clean up SDL and quit
Game::~Game() {
	SDL_Quit();
}

void Game::runGame() {
	bool running = true;
	SDL_Event event;

	while (running == true) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDL_QUIT) {
					running = false;
				}
			}
		}
	}
}