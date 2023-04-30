#pragma once
#include <iostream>
#include "MedicalStaff.h"
#include "MedicalProcedure.h"
#include <list>

class Patient
{
	std::string name;
	int age;
	MedicalStaff* staff;
	std::list<MedicalProcedure*> appointments;

public:
	Patient(const std::string& name, int age, MedicalStaff* staff);
	void information();
	void seeAppointments();
	void removeAppointment(const MedicalProcedure& appointment);
	void setAppointment(MedicalProcedure* appointment);
	MedicalStaff getStaff();
};
