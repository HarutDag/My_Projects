#include "Comment.h"

ImageComment::ImageComment(User* user, Post* post)
{
	commenterUser = user;
	commentedPost = post;
	commentContent = IMAGE;
}
void ImageComment::viewComment() const
{
	std::cout << "Comment from " << commenterUser->seeName() << ":\n";
	std::cout << "Image\n";
}


TextComment::TextComment(User* user, Post* post)
{
	commenterUser = user;
	commentedPost = post;
	commentContent = TEXT;
}
void TextComment::viewComment() const
{
	std::cout << "Comment from " << commenterUser->seeName() << ":\n";
	std::cout << "Text\n";
}