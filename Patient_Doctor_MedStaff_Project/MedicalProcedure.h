#pragma once
#include <iostream>

enum ProcedureType { SURGERIE, CHECKUP };

class MedicalProcedure
{
protected:
	ProcedureType type;

public:
	virtual void doProcedure() = 0;
	virtual ProcedureType seeProcedureType() const = 0;
};

class SurgeriesProcedure: public MedicalProcedure
{
public:
	SurgeriesProcedure();
	void doProcedure();
	ProcedureType seeProcedureType() const;
};

class CheckupProcedure : public MedicalProcedure
{
public:
	CheckupProcedure();
	void doProcedure();
	ProcedureType seeProcedureType() const;
};