#pragma once
#include <iostream>
#include <list>
#include "Patient.h"

class Doctor
{
	std::string name;
	std::string contactInformation;
	std::list<Patient*> patients;

public:
	Doctor(const std::string& name, const std::string& contactInformation);
	void managePatientsInf();
	std::list<Patient*> getPatients();
	void setPatient(Patient& patient);
};