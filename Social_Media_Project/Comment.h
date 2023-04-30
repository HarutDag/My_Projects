#pragma once
#include "Post.h"
#include "User.h"

class Comment
{
protected:
	User* commenterUser;
	Post* commentedPost;
	Content commentContent;
public:
	virtual void viewComment() const = 0;
};

class ImageComment: public Comment
{
public:
	ImageComment(User* user, Post* post);
	void viewComment() const override;
};

class TextComment : public Comment
{
public:
	TextComment(User* user, Post* post);
	void viewComment() const override;
};