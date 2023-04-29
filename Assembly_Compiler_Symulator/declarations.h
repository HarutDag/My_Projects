#pragma once
#include <map>

enum class Opcode
{
	MOV,
	INC,
	DEC,
	ADD,
	SUB,
	MUL,
	DIV,
	CMP,
	JL,
	JG,
	JE,
	JMP,
	AND,
	OR,
	XOR,
	NOT,
	Not_a_opcode = 777
};

enum class Register
{
	R1,
	R2,
	R3,
	R4,
	R5,
	R6,
	R7,
	R8,
	R9,
	R10,
	FLAG,
	Not_a_register = 777
};

Opcode string_to_opcode(std::string color)
{
	if (color == "mov")
		return Opcode::MOV;
	else if (color == "add")
		return Opcode::ADD;
	else if (color == "cmp")
		return Opcode::CMP;
	else if (color == "jl")
		return Opcode::JL;
	else
	{
		std::cout << "Opcode not found\n";
		return Opcode::Not_a_opcode;
	}
}

Register string_to_register(std::string reg)
{
	if (reg == "r1")
		return Register::R1;
	else if (reg == "r2")
		return Register::R2;
	else if (reg == "r3")
		return Register::R3;
	else if (reg == "r4")
		return Register::R4;
	else if (reg == "r5")
		return Register::R5;
	else if (reg == "r6")
		return Register::R6;
	else if (reg == "r7")
		return Register::R7;
	else if (reg == "r8")
		return Register::R8;
	else if (reg == "r9")
		return Register::R9;
	else if (reg == "r10")
		return Register::R10;
	else
	{
		std::cout << "Register not found\n";
		return Register::Not_a_register;
	}
}