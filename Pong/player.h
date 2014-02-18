#ifndef PLAYER_H_
#define PLAYER_H_

class Graphics;
struct SDL_Surface;
struct SDL_Rect;

class Player {
public:
	Player(Graphics& graphics, int id);
	~Player();

	void draw(Graphics& graphics);
	void updateLocation();

	void moveUp();
	void moveDown();
	void stopMoving();
	SDL_Rect getCollisionBox();
	float getYVelocity();
private:
	enum Direction {
		UP,
		DOWN,
		NONE
	};
	float x_, y_;
	float velocity_y_;
	int ID_;
	Direction direction_;
	SDL_Surface* sprite_;
	int score_;
};

#endif // PLAYER_H_