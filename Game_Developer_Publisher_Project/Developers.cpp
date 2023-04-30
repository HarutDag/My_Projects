#include "Developers.h"
#include "Games.h"

Developer::Developer(const std::string& nam, const std::string& contact)
{
	name = nam;
	contactInf = contact;
}

void Developer::createGame()
{
	std::cout << "What type of game you want create:\nTap 1 for Action;\nTap 2 for Strategy;\n";
	int i = 0;
	std::cin >> i;
	std::string name;
	std::string title;
	std::string date;
	std::cout << "Write name, title and date for game\n";
	std::cin >> name >> title >> date;
	switch (i)
	{
	case 1:
		games.push_back(new ActionGame(name, title, date));
		break;
	case 2:
		games.push_back(new StrategyGame(name, title, date));
		break;
	default:
		std::cout << "Not correct type\n";
		break;
	}
}

void Developer::manageGame()
{
	for (Game* g : games)
	{
		g->information();
	}
}

Game* Developer::getOneGame()
{
	int num = 0;
	for (Game* g : games)
	{
		g->information();
		std::cout << "Are you want get this game?\nIf yes, tap 1\n";
		std::cin >> num;
		switch (num)
		{
		case 1:
			return g;
		default:
			break;
		}
	}
}
