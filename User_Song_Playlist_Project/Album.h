#pragma once
#include <iostream>
#include <vector>
#include "Song.h"

class Album
{
	std::string title;
	std::string artist;
	std::string releaseDate;
	std::vector<Song*> albumSongs;

public:
	const Song* const getSong(Song* wishSong);
	void setSong(Song&);
};
