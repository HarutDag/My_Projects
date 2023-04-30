#pragma once
#include "User.h"

enum Content { IMAGE, TEXT };

class Post
{
public:
	virtual void setComment(Comment*) = 0;
	virtual Content getContent() const = 0;
	virtual Post* viewPost() const = 0;
	virtual ~Post() = 0;
};

class Image : public Post
{
	User* postUser;
	Content content;
	std::string data;
	double capacity;
	std::vector<Comment*> postComments;

public:
	Image(User* user, std::string data, double cap);
	void setComment(Comment* comment) override;
	Post* viewPost() const override;
	Content getContent() const override;
};

class Text: public Post
{
	User* postUser;
	Content content;
	std::string data;
	int lenght;
	std::vector<Comment*> postComments;

public:
	Text(User* user, std::string data, int len);
	void setComment(Comment* comment) override;
	Post* viewPost() const override;
	Content getContent() const override;
};