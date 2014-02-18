#include "player.h"

#include <SDL.h>
#include "graphics.h"
#include "game.h"

#include <cmath>

const int paddleHeight = 160;
const int paddleWidth = 32;

const float maxVelocity = 3.15f;
const float paddleAcceleration = 0.0888f;
const float paddleDeceleration = 0.83f;

const std::string paddleFile = "../content/paddle.bmp";

//Position the paddle one "unit" away from the screen edge
Player::Player(Graphics& graphics, int id) {
	if (id == 1) {
		x_ = (float) paddleWidth;
	}
	else if (id == 2) {
		x_ = (float) Game::gameScreenWidth - 2 * paddleWidth;
	}

	y_ = (float) (Game::gameScreenHeight - paddleHeight) / 2;
	velocity_y_ = 0.0f;
	direction_ = NONE;

	score_ = 0;

	sprite_ = graphics.loadImage(paddleFile);
}


Player::~Player() {
	SDL_FreeSurface(sprite_);
}

//blit the player on the screen
void Player::draw(Graphics& graphics) {
	SDL_Rect location;
	location.x = (int)x_;
	location.y = (int)y_;
	graphics.blitScreen(sprite_, NULL, &location);
}

//move the y coordinate of the player paddle, keeping it in the game screen
void Player::updateLocation() {
	if (direction_ == UP) {
		velocity_y_ = std::fmax(velocity_y_ - paddleAcceleration, -maxVelocity);
		y_ += velocity_y_;
		if (y_ < 0.0f) {
			y_ = 0.0f;
			velocity_y_ = 0.0f;
		}
	}
	else if (direction_ == DOWN) {
		velocity_y_ = std::fmin(velocity_y_ + paddleAcceleration, maxVelocity);
		y_ += velocity_y_;
		if (y_ > (float) Game::gameScreenHeight - paddleHeight) {
			y_ = (float) Game::gameScreenHeight - paddleHeight;
			velocity_y_ = 0.0f;
		}
	}
	else if (direction_ == NONE) {
		velocity_y_ *= paddleDeceleration;
		y_ += velocity_y_;
		if (y_ < 0.0f) {
			y_ = 0.0f;
			velocity_y_ = 0.0f;
		}
		if (y_ >(float) Game::gameScreenHeight - paddleHeight) {
			y_ = (float)Game::gameScreenHeight - paddleHeight;
			velocity_y_ = 0.0f;
		}
	}
}

void Player::moveUp() {
	direction_ = UP;
}

void Player::moveDown() {
	direction_ = DOWN;
}

void Player::stopMoving() {
	direction_ = NONE;
}

SDL_Rect Player::getCollisionBox() {
	SDL_Rect box = { (int)x_, (int)y_, paddleWidth, paddleHeight };
	return box;
}

float Player::getYVelocity() {
	if (direction_ == UP) {
		return -maxVelocity;
	}
	else if (direction_ == DOWN) {
		return maxVelocity;
	}
	else {
		return 0.0f;
	}
}