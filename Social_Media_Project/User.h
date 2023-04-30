#pragma once
#include "Post.h"
#include "SocialMediaOperation.h"
#include <iostream>
#include <vector>

class User
{
	std::string name;
	std::string contactInformation;
	std::vector<Post*> userPosts;

public:
	User(std::string name, std::string contactInformation);
	void setName(std::string name);
	void setContactInformation(std::string contInf);
	void setPost(Post* post);
	std::vector<Post*> getPosts() const;
	std::string seeName() const;
};
