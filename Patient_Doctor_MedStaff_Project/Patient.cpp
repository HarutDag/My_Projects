#include "Patient.h"

Patient::Patient(const std::string& name, int age, MedicalStaff* staff)
{
	this->name = name;
	this->age = age;
	this->staff = staff;
}

void Patient::information()
{
	std::cout << "Patient name: " << name << '\n';
	std::cout << "Age: " << age << '\n';
}

void Patient::seeAppointments()
{
	for (MedicalProcedure* prod : appointments)
	{
		prod->doProcedure();
		removeAppointment(*prod);
	}
}

void Patient::removeAppointment(const MedicalProcedure& appointment)
{
	MedicalProcedure* proc;
	for (MedicalProcedure* proc : appointments)
		if (proc->seeProcedureType() == appointment.seeProcedureType())
			appointments.remove(proc);
}

void Patient::setAppointment(MedicalProcedure* appointment)
{
	appointments.push_back(appointment);
}

MedicalStaff Patient::getStaff()
{
	return *staff;
}
