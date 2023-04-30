#pragma once
#include <iostream>

class Song
{
	std::string title;
	std::string artist;
	int lenght;

public:
	Song(const std::string&, const std::string&, int);
	void listen() const;
	bool operator==(const Song&);
};
