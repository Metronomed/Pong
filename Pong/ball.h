#ifndef BALL_H_
#define BALL_H_

class Graphics;
struct SDL_Surface;
struct SDL_Rect;

class Ball {
public:
	Ball(Graphics& graphics);
	~Ball();

	void updateLocation();
	void draw(Graphics& graphics);
	void detectCollision(SDL_Rect* other_rect);
private:
	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	float center_x_, center_y_;
	float velocity_x_, velocity_y_;
	SDL_Surface* sprite_;
	void reflectOffSurface(Direction direction, float offset);
};

#endif // BALL_H_