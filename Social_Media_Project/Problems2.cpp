#include "Comment.h"
#include "Post.h"
#include "SocialMediaOperation.h"
#include "User.h"

int main()
{
	User firstUser("John", "555");
	User secondUser("Harut", "777");

	CreateOperation crOp;
	ManageOperation mnOp;
	crOp.createPost(&firstUser);
	crOp.leaveComment(mnOp.manageProfile(firstUser), &secondUser);

	return 0;
}