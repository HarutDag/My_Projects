#include "Playlist.h"

const std::vector<Song*> Playlist::getPlaylist() const { return songs; }
void Playlist::setSong(Song& song) { songs.push_back(&song); }