#include "Song.h"

Song::Song(const std::string& title, const std::string& artist, int lenght)
{
	this->title = title;
	this->artist = artist;
	this->lenght = lenght;
}
void Song::listen() const { std::cout << "Playing " << title << " song of " << artist << " artist\n"; }
bool Song::operator==(const Song& song)
{
	return title == song.title && artist == song.artist && lenght == song.lenght;
}