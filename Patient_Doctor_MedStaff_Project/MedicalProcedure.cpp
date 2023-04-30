#include "MedicalProcedure.h"

SurgeriesProcedure::SurgeriesProcedure()
{
	type = SURGERIE;
}

void SurgeriesProcedure::doProcedure()
{
	std::cout << "Surgerie procedure was complited\n";
}

ProcedureType SurgeriesProcedure::seeProcedureType() const
{
	return SURGERIE;
}

CheckupProcedure::CheckupProcedure()
{
	type = CHECKUP;
}

void CheckupProcedure::doProcedure()
{
	std::cout << "Checkup procedure was complited\n";
}

ProcedureType CheckupProcedure::seeProcedureType() const
{
	return CHECKUP;
}
