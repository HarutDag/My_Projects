#pragma once
#include <iostream>
#include <vector>
#include "Doctor.h"

class MedicalStaff
{
	std::string name;
	std::string position;
	std::vector<Doctor*> hospitalDoctors;

public:
	MedicalStaff(const std::string& name, const std::string& position);
	void manageHospital();
	void information();

};