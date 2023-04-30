#include "Course.h"

AssignmentType BanavorAssignments::getType() const
{
	return AssignmentType();
}

AssignmentType GravorAssignment::getType() const
{
	return AssignmentType();
}

Course::Course(std::string name, Professor prof, Content cont): instructor{prof}
{
	this->name = name;
	content = cont;
}

void Course::setStudent(Student& newStudent)
{
	students.push_back(newStudent);
}

std::vector<CourseAssignments*> Course::getAssingments() const
{
	return assignments;
}
