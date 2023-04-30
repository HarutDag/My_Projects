#pragma once
#include <iostream>
#include <vector>

class Game;

class Developer
{
	std::string name;
	std::string contactInf;
	std::vector<Game*> games;

public:
	Developer(const std::string& nam, const std::string& contact);
	void createGame();
	void manageGame();
	Game* getOneGame();
};
