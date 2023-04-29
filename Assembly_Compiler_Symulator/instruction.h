#pragma once
#include "declarations.h"

struct instruction
{
	Opcode opcode;
	Register dest_reg;
	Register src_reg;
	int src_imm_value;
	bool is_src_imm;
	int target;
};