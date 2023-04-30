#include "Professor.h"

Professor::Professor(std::string name, std::string conInf)
{
	this->name = name;
	contactInformation = conInf;
}

void Professor::createCourse(std::string name, Content content)
{
	courses.push_back(new Course(name, *this, content));
}

void Professor::manageCourse()
{

}