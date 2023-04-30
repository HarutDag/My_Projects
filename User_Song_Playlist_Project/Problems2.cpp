#include "Album.h"
#include "Playlist.h"
#include "Song.h"
#include "User.h"

int main()
{
	Playlist playlist;
	Song firstSong("song1", "first", 5);
	Song secondSong("song2", "second", 6);
	Song thirdSong("song3", "third", 7);

	playlist.setSong(firstSong);
	playlist.setSong(secondSong);
	playlist.setSong(thirdSong);

	Album album;
	album.setSong(firstSong);

	User user;
	user.playSong(user.serchSong(playlist, secondSong));

	return 0;
}