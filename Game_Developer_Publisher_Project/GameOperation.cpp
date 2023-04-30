#include "GameOperation.h"
#include "Games.h"

PlayGame::PlayGame(Game* game)
{
	this->game = game;
}

void PlayGame::seeGameInfo()
{
	game->information();
}

void PlayGame::playGame()
{
	std::cout << "I play game\n";
	game->information();
}

ExitGame::ExitGame(Game* game)
{
	this->game = game;
}

void ExitGame::seeGameInfo()
{
	game->information();
}

void ExitGame::exitGame()
{
	std::cout << "I exit game\n";
	game->information();
}
