#include "Album.h"

const Song* const Album::getSong(Song* wishSong)
{
	for (const Song* const song : albumSongs)
	{
		if (*wishSong == *song)
			return wishSong;
	}
}
void Album::setSong(Song& song) { albumSongs.push_back(&song); }