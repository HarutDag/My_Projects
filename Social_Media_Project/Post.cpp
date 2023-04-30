#include "Post.h"

Image::Image(User* user, std::string data, double cap)
{
	postUser = user;
	this->data = data;
	capacity = cap;
	content = IMAGE;
}
void Image::setComment(Comment* comment)
{
	postComments.push_back(comment);
}
Post* Image::viewPost() const
{
	std::cout << postUser->seeName() << '\t';
	std::cout << data << '\n';
	/*switch (content)
	{
	case IMAGE: 
		std::cout << "Image\n";
		break;
	case TEXT:
		std::cout << "Text\n";
		break;
	default:
		std::cout << "Not founded post type\n";
	}*/
	std::cout << "Image\n";
	for (const Comment* comment : postComments)
	{
		comment->viewComment();
	}

	return nullptr;
}
Content Image::getContent() const
{
	return IMAGE;
}


Text::Text(User* user, std::string data, int len)
{
	postUser = user;
	this->data = data;
	lenght = len;
	content = TEXT;
}
void Text::setComment(Comment* comment)
{
	postComments.push_back(comment);
}
Post* Text::viewPost() const
{
	std::cout << postUser->seeName() << '\t';
	std::cout << data << '\n';
	std::cout << "Image\n";
	for (const Comment* comment : postComments)
	{
		comment->viewComment();
	}

	std::cout << "If you won leave comment on this post, please tap y\n";
	char ch = 0;
	std::cin >> ch;
	if (ch == 'y')
		return (Post*)this;
	return nullptr;
}
Content Text::getContent() const
{
	return TEXT;
}
