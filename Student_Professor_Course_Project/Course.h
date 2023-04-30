#pragma once
#include <iostream>
#include "Professor.h"
#include "Student.h"

// name, instructor, and content
// undergraduate, graduate

enum Content { FIRST, SECOND };

enum AssignmentType { BANAVOR, GRAVOR };

class CourseAssignments
{
protected:
	AssignmentType assignmentType;
	std::vector<std::string> assignments;
	int countOfAssignments;

public:
	virtual AssignmentType getType() const = 0;
};

class BanavorAssignments: public CourseAssignments
{
public:
	AssignmentType getType() const override;
};

class GravorAssignment : public CourseAssignments
{
public:
	AssignmentType getType() const override;
};

class Course
{
	std::string name;
	Professor instructor;
	Content content;
	std::vector<CourseAssignments*> assignments;
	std::vector<Student> students;

public:
	Course(std::string name, Professor prof, Content cont);
	void setStudent(Student& newStudent);
	std::vector<CourseAssignments*> getAssingments() const;
};