#pragma once
#include <iostream>
#include <vector>
#include "Course.h"

class Student
{
	std::string name;
	std::string contactInformation;
	std::vector<Course> courses;
	int assignmentsCompleted;

public:
	void enrollCourse(Course& course);
	void compliteAssignments();
	void viewProgress();
};