#pragma once
#include "User.h"
#include "Post.h"
#include "Comment.h"

enum OperationType { CREATE, MANAGE };

class Operation
{
public:
	virtual OperationType getOperationType() const = 0;
};

class CreateOperation : public Operation
{
public:
	void createPost(User* user);
	void leaveComment(Post* post, User* commenter);
	OperationType getOperationType() const override;
};

class ManageOperation : public Operation
{
public:
	Post* manageProfile(const User& user);
	OperationType getOperationType() const override;
};