#include "ball.h"

#include "graphics.h"
#include <SDL.h>

const std::string ballFile = "../content/ball.bmp";
const int ballRadius = 32 / 2;

const float ball_velocity_x = 3.9f;
const float init_ball_velocity_y = 2.3f;

Ball::Ball(Graphics& graphics) {
	sprite_ = graphics.loadImage(ballFile, true);
	center_x_ = 0.f;
	center_y_ = 0.f;
	velocity_x_ = ball_velocity_x;
	velocity_y_ = init_ball_velocity_y;
}

Ball::~Ball() {
	SDL_FreeSurface(sprite_);
}

void Ball::draw(Graphics& graphics) {
	SDL_Rect location;
	location.x = (int) center_x_ - ballRadius;
	location.y = (int) center_y_ - ballRadius;
	graphics.blitScreen(sprite_, NULL, &location);
}

//changes ball velocity with respect to the direction of a surface, compared to the ball
void Ball::reflectOffSurface(Direction direction, int offset) {
	if (direction == UP) {
		velocity_y_ = -velocity_y_;
		center_y_ += offset;
	}
	else if (direction == DOWN) {
		velocity_y_ = -velocity_y_;
		center_y_ -= offset;
	}
	else if (direction == LEFT) {
		velocity_x_ = -velocity_x_;
		center_x_ += offset;
	}
	else if (direction == RIGHT) {
		velocity_x_ = -velocity_x_;
		center_x_ -= offset;
	}
}

//check distance of rect lines from circle
void Ball::detectCollision(SDL_Rect* other_rect) {
	//left side
	int delta_left = center_x_ - other_rect->x;
	if (delta_left * delta_left <= ballRadius * ballRadius) {
		reflectOffSurface(LEFT);
	}
	int delta_right = center_x_ - (other_rect->x + other_rect->w);
	if (delta_right * delta_right <= ballRadius * ballRadius) {
		reflectOffSurface(RIGHT);
	}
	int delta_up = center_y_ - other_rect->y;
	if (delta_up * delta_up <= ballRadius * ballRadius) {
		reflectOffSurface(UP);
	}
	int delta_down = center_y_ - (other_rect->y + other_rect->h);
	if (delta_down * delta_down <= ballRadius * ballRadius) {
		reflectOffSurface(DOWN);
	}
}