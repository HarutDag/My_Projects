#pragma once
#include "Song.h"
#include <vector>

class Playlist
{
	std::string name;
	std::vector<Song*> songs;

public:
	const std::vector<Song*> getPlaylist() const;
	void setSong(Song&);
};
