#ifndef GAME_H_
#define GAME_H_

class Game {
public:
	Game();
	~Game();

	static int gameScreenWidth;
	static int gameScreenHeight;
	static int gameFPS;
private:
	void runGame();
};
#endif // GAME_H_