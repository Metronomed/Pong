#ifndef PLAYER_H_
#define PLAYER_H_

class Graphics;
struct SDL_Surface;

class Player {
public:
	Player(Graphics& graphics, int id);
	~Player();

	void draw(Graphics& graphics);
	void updateLocation();

	void moveUp();
	void moveDown();
	void stopMoving();
private:
	enum Direction {
		UP,
		DOWN,
		NONE
	};
	float x_, y_;
	int ID_;
	Direction direction_;
	SDL_Surface* sprite_;
};

#endif // PLAYER_H_