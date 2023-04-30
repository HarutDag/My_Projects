#include "Doctor.h"

Doctor::Doctor(const std::string& name, const std::string& contactInformation)
{
	this->name;
	this->contactInformation = contactInformation;
}

void Doctor::managePatientsInf()
{
	for (Patient* patient : patients)
	{
		patient->information();
		bool manage = true;
		while (manage)
		{
			std::cout << "What you want to change for this patient?\nTap one of numbers for:\n"
				<< "1. Set appointment\n2. Remove appointment\n";
			int i = 0;
			std::cin >> i;
			switch (i)
			{
			case 1:
				std::cout << "What cinde appointment you wan to set?\nTap one of numbers for:\n"
					<< "1. Surgerie\n2. Checkup\n";
				int i = 0;
				std::cin >> i;
				switch (i)
				{
				case 1:
					patient->setAppointment(new SurgeriesProcedure());
					break;
				case 2:
					patient->setAppointment(new CheckupProcedure());
					break;
				default:
					std::cout << "Uncorrect number\n";
				}
			case 2:
				std::cout << "What cinde appointment you wan to remove?\nTap one of numbers for:\n"
					<< "1. Surgerie\n2. Checkup\n";
				int i = 0;
				std::cin >> i;
				switch (i)
				{
				case 1:
					patient->removeAppointment(SurgeriesProcedure());
					break;
				case 2:
					patient->removeAppointment(CheckupProcedure());
					break;
				default:
					std::cout << "Uncorrect number\n";
				}
			default:
				std::cout << "Uncorrect number\n";
			}
			std::cout << "If you done tap 0, else tap any number\n";
			std::cin >> manage;
		}
	}
}

std::list<Patient*> Doctor::getPatients()
{
	return std::list<Patient*>();
}

void Doctor::setPatient(Patient& patient)
{
	patients.push_back(&patient);
}
