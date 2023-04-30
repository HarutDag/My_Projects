#pragma once
#include <iostream>
#include <vector>
class Game;
class Publisher
{
	std::string name;
	std::string contactInf;
	std::vector<Game*> games;
	std::vector<Game*> saledGames;

public:
	Publisher(const std::string& nam, const std::string& contact);
	void getGame(Game* game);
	void manageRelease();
	void manageSell();
	void sellGame();
};
