#pragma once
#include <iostream>
#include <vector>
#include "Course.h"

class Professor
{
	std::string name;
	std::string contactInformation;
	std::vector<Course*> courses;

public:
	Professor(std::string name, std::string conInf);
	void createCourse(std::string name, Content content);
	void manageCourse();
};
