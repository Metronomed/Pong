#ifndef BALL_H_
#define BALL_H_

class Graphics;
struct SDL_Surface;

class Ball {
public:
	Ball(Graphics& graphics);
	~Ball();

	void draw(Graphics& graphics);
private:
	enum Direction {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
	int center_x_, center_y_;
	float velocity_x_, velocity_y_;
	SDL_Surface* sprite_;
	void reflectVelocity(Direction direction);
};

#endif // BALL_H_