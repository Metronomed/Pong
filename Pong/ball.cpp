#include "ball.h"

#include "graphics.h"
#include <SDL.h>

const std::string ballFile = "../content/ball.bmp";
const int ballRadius = 32 / 2;

const float ball_velocity_x = 2.9f;
const float init_ball_velocity_y = 2.3f;

Ball::Ball(Graphics& graphics) {
	sprite_ = graphics.loadImage(ballFile, true);
	center_x_ = 320.f;
	center_y_ = 240.f;
	velocity_x_ = ball_velocity_x;
	velocity_y_ = init_ball_velocity_y;
}

Ball::~Ball() {
	SDL_FreeSurface(sprite_);
}

void Ball::updateLocation() {
	center_x_ += velocity_x_;
	center_y_ += velocity_y_;
}

void Ball::draw(Graphics& graphics) {
	SDL_Rect location;
	location.x = (int) center_x_ - ballRadius;
	location.y = (int) center_y_ - ballRadius;
	graphics.blitScreen(sprite_, NULL, &location);
}

//changes ball velocity based on what side of the ball collided
void Ball::reflectOffSurface(Direction direction, float offset) {
	if (direction == UP) {
		velocity_y_ = std::abs(velocity_y_);
		center_y_ += std::abs(offset);
	}
	else if (direction == DOWN) {
		velocity_y_ = -std::abs(velocity_y_);
		center_y_ -= std::abs(offset);
	}
	else if (direction == LEFT) {
		velocity_x_ = std::abs(velocity_x_);
		center_x_ += std::abs(offset);
	}
	else if (direction == RIGHT) {
		velocity_x_ = -std::abs(velocity_x_);
		center_x_ -= std::abs(offset);
	}
}

//check distance of rect lines from circle
//behavior not as good if it hits a corner
//maybe add cases for when it does hit a corner
void Ball::detectCollision(SDL_Rect* other_rect) {
	//left side of the circle = right side of rect
	float delta_x = center_x_ - other_rect->x;
	if (delta_x * delta_x <= ballRadius * ballRadius) {
		if ((center_y_ >= other_rect->y) && (center_y_ <= other_rect->y + other_rect->h)) { //if the center is within the y-bounds of other
			reflectOffSurface(RIGHT, delta_x);
		}
	}

	delta_x = center_x_ - (other_rect->x + other_rect->w);
	if (delta_x * delta_x <= ballRadius * ballRadius) {
		if ((center_y_ >= other_rect->y) && (center_y_ <= other_rect->y + other_rect->h)) { //if the center is within the y-bounds of other
			reflectOffSurface(LEFT, delta_x);
		}
	}

	float delta_y = center_y_ - other_rect->y;
	if (delta_y * delta_y <= ballRadius * ballRadius) {
		if ((center_x_ >= other_rect->x) && (center_x_ <= other_rect->x + other_rect->w)) { //if the center is within the w-bounds of other
			reflectOffSurface(DOWN, delta_y);
		}
	}

	delta_y = center_y_ - (other_rect->y + other_rect->h);
	if (delta_y * delta_y <= ballRadius * ballRadius) {
		if ((center_x_ >= other_rect->x) && (center_x_ <= other_rect->x + other_rect->w)) { //if the center is within the w-bounds of other
			reflectOffSurface(UP, delta_y);
		}
	}
}