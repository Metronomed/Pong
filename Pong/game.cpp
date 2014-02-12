#include "game.h"

#include <SDL.h>
#include "graphics.h"
#include "player.h"

//declaring game window size
int Game::gameScreenWidth = 640;
int Game::gameScreenHeight = 480;

//declaring game's FPS
int Game::gameFPS = 60;

//initialize SDL and start it running
Game::Game() {
	SDL_Init(SDL_INIT_EVERYTHING);
	runGame();
	player_1_ = NULL;
	player_2_ = NULL;
	ball_ = NULL;
}

//clean up SDL and quit
Game::~Game() {
	delete player_1_;
	delete player_2_;
	SDL_Quit();
}

// Run the game loop
void Game::runGame() {
	bool running = true;
	SDL_Event event;
	Graphics graphics;
	player_1_ = new Player(graphics, 1);
	player_2_ = new Player(graphics, 2);
	ball_ = new Ball(graphics);

	//Game loop for each frame
	while (running == true) {
		const int frameStartTime = SDL_GetTicks();
		//For now, just quit when esc is pressed
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					running = false;
				}
			}
		}
		
		drawGame(graphics);

		//force game to run at no more than desired FPS
		const int elapsedTime = SDL_GetTicks() - frameStartTime;
		const int frameTime = 1000 / gameFPS;
		if (elapsedTime < frameTime) {
			SDL_Delay(frameTime - elapsedTime);
		}

	}
}

void Game::drawGame(Graphics& graphics) {
	graphics.clear();
	player_1_->draw(graphics);
	player_2_->draw(graphics);
	ball_->draw(graphics);
	graphics.flip();
}