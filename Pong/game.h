#ifndef GAME_H_
#define GAME_H_

#include "player.h"

class Game {
public:
	Game();
	~Game();

	static int gameScreenWidth;
	static int gameScreenHeight;
	static int gameFPS;
private:
	void runGame();
	Player* player_1_;
	Player* player_2_;
};
#endif // GAME_H_