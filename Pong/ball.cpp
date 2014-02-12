#include "ball.h"

#include "graphics.h"
#include <SDL.h>

const std::string ballFile = "../content/ball.bmp";
const int ballRadius = 32 / 2;

Ball::Ball(Graphics& graphics) {
	sprite_ = graphics.loadImage(ballFile, true);
	center_x_ = 0;
	center_y_ = 0;
}

Ball::~Ball() {
	SDL_FreeSurface(sprite_);
}

void Ball::draw(Graphics& graphics) {
	SDL_Rect location;
	location.x = center_x_ - ballRadius;
	location.y = center_y_ - ballRadius;
	graphics.blitScreen(sprite_, NULL, &location);
}