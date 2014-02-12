#include "game.h"

#include <SDL.h>
#include "graphics.h"
#include "player.h"

//declaring game window size
int Game::gameScreenWidth = 640;
int Game::gameScreenHeight = 480;

//declaring game's FPS
int Game::gameFPS = 60;

//setting player controls here
const SDLKey player_1_up = SDLK_w;
const SDLKey player_1_down = SDLK_s;
const SDLKey player_2_up = SDLK_UP;
const SDLKey player_2_down = SDLK_DOWN;

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
	//variable initializations
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
				switch (event.key.keysym.sym) {
				case SDLK_ESCAPE:
					running = false;
					break;
				case player_1_up:
					player_1_->moveUp();
					break;
				case player_1_down:
					player_1_->moveDown();
					break;
				case player_2_up:
					player_2_->moveUp();
					break;
				case player_2_down:
					player_2_->moveDown();
					break;

				}
			}
		}
		
		//perform updates on the ball location
		player_1_->updateLocation();
		player_2_->updateLocation();
		ball_->updateLocation();
		SDL_Rect p1_box = player_1_->getCollisionBox();
		SDL_Rect p2_box = player_2_->getCollisionBox();


		ball_->updateLocation();
		drawGame(graphics);

		//force game to run at no more than desired FPS
		const int elapsedTime = SDL_GetTicks() - frameStartTime;
		const int frameTime = 1000 / gameFPS;
		if (elapsedTime < frameTime) {
			SDL_Delay(frameTime - elapsedTime);
		}

	}
}

//draw everything to the screen
void Game::drawGame(Graphics& graphics) {
	graphics.clear();
	player_1_->draw(graphics);
	player_2_->draw(graphics);
	ball_->draw(graphics);
	graphics.flip();
}