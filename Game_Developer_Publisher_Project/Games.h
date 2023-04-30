#pragma once
#include <iostream>
#include "GameOperation.h"

class GameOperation;
class ExitGame;
class PlayGame;

class Game
{
protected:
	std::string title;
	std::string genre;
	std::string date;

public:
	virtual void information() = 0;
};

class ActionGame: public Game
{
public:
	PlayGame play;
	ExitGame exit;
	ActionGame(const std::string& tit, const std::string& gen, const std::string& dat);
	void information() override;
};

class StrategyGame : public Game
{
public:
	PlayGame play;
	ExitGame exit;
	StrategyGame(const std::string& tit, const std::string& gen, const std::string& dat);
	void information() override;
};
