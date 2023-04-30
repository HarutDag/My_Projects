#include "MedicalStaff.h"

MedicalStaff::MedicalStaff(const std::string& name, const std::string& position)
{
	this->name = name;
	this->position = position;
}

void MedicalStaff::manageHospital()
{
	for (Doctor* doctor : hospitalDoctors)
	{
		std::list<Patient*> patients = doctor->getPatients();
		
		for (Patient* patient : patients)
		{
			if (this->name == patient->getStaff().name)
			{
				patient->seeAppointments();
				bool areDone = true;
				while (areDone)
				{
					std::cout << "What cinde appointment you won to done?\nTap one of numbers for:\n"
						<< "1. Surgerie\n2. Checkup\n 3. If all";
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
					std::cout << "If you done tap 0, else tap any number\n";
					std::cin >> areDone;
				}
			}
		}
	}
}

void MedicalStaff::information()
{
	std::cout << "Name of staff: " << name << '\n';
	std::cout << "Position of staff: " << position << '\n';
}
