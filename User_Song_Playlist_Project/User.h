#pragma once
#include "Playlist.h"
#include "Album.h"

class User
{
	mutable std::vector<Song*> listeningHistory;
	mutable std::vector<Song*> playlist;

public:
	Song* serchSong(const Playlist& playlist, Song& wishSong) const;
	void playSong(Song*) const;
};