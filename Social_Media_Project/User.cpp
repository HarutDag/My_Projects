#include "User.h"

User::User(std::string name, std::string contactInformation)
{
	this->name = name;
	this->contactInformation = contactInformation;
}
void User::setName(std::string name)
{
	this->name = name;
}
void User::setContactInformation(std::string contInf)
{
	contactInformation = contInf;
}
void User::setPost(Post* post)
{
	userPosts.push_back(post);
}
std::vector<Post*> User::getPosts() const { return userPosts; }

std::string User::seeName() const
{
	return name;
}
