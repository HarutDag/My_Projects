#include "Developers.h"
#include "Games.h"
#include "Publishers.h"
#include "GameOperation.h"

int main()
{
	Developer dev("John", "555");
	dev.createGame();
	dev.createGame();
	dev.manageGame();

	Publisher pub("Harut", "777");
	pub.getGame(dev.getOneGame());
	std::cout << "\n\nManage release\n\n";
	pub.manageRelease();

	pub.sellGame();
	std::cout << "\n\nManage sell\n\n";
	pub.manageSell();

	return 0;
}