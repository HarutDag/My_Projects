#include "Games.h"

ActionGame::ActionGame(const std::string& tit, const std::string& gen, const std::string& dat): play(this), exit(this)
{
	title = tit;
	genre = gen;
	date = dat;
}

void ActionGame::information()
{
	std::cout << "Action:\nTitle: " << title << "\nGenre: " << genre << "\nDate: " << date << '\n';
}

StrategyGame::StrategyGame(const std::string& tit, const std::string& gen, const std::string& dat): play(this), exit(this)
{
	title = tit;
	genre = gen;
	date = dat;
}

void StrategyGame::information()
{
	std::cout << "Strategy:\nTitle: " << title << "\nGenre: " << genre << "\nDate: " << date << '\n';
}
