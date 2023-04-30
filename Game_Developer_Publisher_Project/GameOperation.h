#pragma once
class Game;
class GameOperations
{
protected:
	Game* game;
	virtual void seeGameInfo() = 0;
};

class PlayGame: public GameOperations
{
public:
	PlayGame(Game* game);
	void seeGameInfo();
	void playGame();
};

class ExitGame : public GameOperations
{
public:
	ExitGame(Game* game);
	void seeGameInfo();
	void exitGame();
};