#ifndef PLAYER_H_
#define PLAYER_H_

class Graphics;
struct SDL_Surface;

class Player {
public:
	Player(Graphics& graphics, int id);
	~Player();
	void draw(Graphics& graphics);
	void moveUp();
	void moveDown();
private:
	int x_, y_;
	int ID_;
	float velocity_y_;
	SDL_Surface* sprite_;
};

#endif // PLAYER_H_