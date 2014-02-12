#include "player.h"

#include <SDL.h>
#include "graphics.h"
#include "game.h"

const int paddleHeight = 160;
const int paddleWidth = 32;

const float paddleAcceleration = 0.004f;
const float maxVelocity = 0.4f;

const std::string paddleFile = "../content/paddle.bmp";

Player::Player(Graphics& graphics, int id) {
	if (id == 1) {
		x_ = paddleWidth;
	}
	else if (id == 2) {
		x_ = Game::gameScreenWidth - 2 * paddleWidth;
	}

	y_ = (Game::gameScreenHeight - paddleHeight) / 2;

	velocity_y_ = 0.0f;

	sprite_ = graphics.loadImage(paddleFile);
}


Player::~Player() {
	SDL_FreeSurface(sprite_);
}

//blit the player on the screen
void Player::draw(Graphics& graphics) {
	SDL_Rect location;
	location.x = x_;
	location.y = y_;

	graphics.blitScreen(sprite_, NULL, &location);
}

void Player::moveUp() {

}

void Player::moveDown() {

}