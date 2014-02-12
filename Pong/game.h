#ifndef GAME_H_
#define GAME_H_

#include "player.h"
#include "ball.h"

class Graphics;

class Game {
public:
	Game();
	~Game();

	static int gameScreenWidth;
	static int gameScreenHeight;
	static int gameFPS;
private:
	void runGame();
	void drawGame(Graphics& graphics);
	
	Player* player_1_;
	Player* player_2_;
	Ball* ball_;
};
#endif // GAME_H_