#include "User.h"

Song* User::serchSong(const Playlist& playlist, Song& wishSong) const
{
	const std::vector<Song*> songs = playlist.getPlaylist();
	for (Song* song : songs)
	{
		if (*song == wishSong)
			return &wishSong;
		else
			return nullptr;
	}
}

void User::playSong(Song* song) const
{
	song->listen();
	std::cout << "Are you like this song and won to add this to your playlist?\nIf no, pleas tap 0\n";
	bool b = false;
	std::cin >> b;
	if (b)
		playlist.push_back(song);
}