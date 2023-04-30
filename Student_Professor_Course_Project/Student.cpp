#include "Student.h"

void Student::enrollCourse(Course& course)
{
	course.setStudent(*this);
}

void Student::compliteAssignments()
{
	for (const Course& course : courses)
	{
		for (const auto& i : course.getAssingments())
			++assignmentsCompleted;
	}
}

void Student::viewProgress()
{
	std::cout << "You done " << assignmentsCompleted << " assignments\n";
}