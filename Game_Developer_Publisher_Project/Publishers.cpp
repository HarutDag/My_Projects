#include "Publishers.h"
#include "Games.h"

Publisher::Publisher(const std::string& nam, const std::string& contact)
{
	name = nam;
	contactInf = contact;
}

void Publisher::getGame(Game* game)
{
	if (game)
		games.push_back(game);
}

void Publisher::manageRelease()
{
	for (Game* game : games)
		game->information();
}

void Publisher::manageSell()
{
	for (Game* g : saledGames)
	{
		g->information();
		std::cout << '\n';
	}
}

void Publisher::sellGame()
{
	int i = false;
	for (Game* game : games)
	{
		game->information();
		std::cout << "If you want buy this game, tap 1\n";
		std::cin >> i;
		if (i)
			saledGames.push_back(game);
	}
}
