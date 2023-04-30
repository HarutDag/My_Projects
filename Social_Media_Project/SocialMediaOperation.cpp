#include "SocialMediaOperation.h"

void CreateOperation::createPost(User* user)
{
	std::cout << "What cinde of post you won to create?\nPlease select one of this cindes\n"
		<< "Tap 1 for create Image type post\nTap 2 for create Text type post\n";
	int i = 0;
	std::cin >> i;
	switch (i)
	{
	case 1:
		user->setPost(new Image(user, "private data", 5));
		break;
	case 2:
		user->setPost(new Text(user, "private data", 1));
		break;
	default:
		std::cout << "Uncorrect Type choosing\n";
	}
}
void CreateOperation::leaveComment(Post* post, User* commenter)
{
	std::cout << "What cinde of comment you won to create?\nPlease select one of this cindes\n"
		<< "Tap 1 for create Image type comment\nTap 2 for create Text type comment\n";
	int i = 0;
	std::cin >> i;
	switch (i)
	{
	case 1:
		post->setComment(new ImageComment(commenter, post));
		break;
	case 2:
		post->setComment(new TextComment(commenter, post));
		break;
	default:
		std::cout << "Uncorrect type choosing\n";
	}
}
OperationType CreateOperation::getOperationType() const
{
	return CREATE;
}



Post* ManageOperation::manageProfile(const User& post)
{
	for (const Post* post : post.getPosts())
	{
		post->viewPost();
	}

	return nullptr;
}
OperationType ManageOperation::getOperationType() const
{
	return MANAGE;
}