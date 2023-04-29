#pragma once
#include "instruction.h"

struct cpu
{
	std::map<Register, int> registers;
};

void init_cpu(cpu* c)
{
	c->registers[Register::R1] = 1;
	c->registers[Register::R2] = 2;
	c->registers[Register::R3] = 3;
	c->registers[Register::R4] = 4;
	c->registers[Register::R5] = 5;
	c->registers[Register::R6] = 0;
	c->registers[Register::R7] = 0;
	c->registers[Register::R8] = 0;
	c->registers[Register::R9] = 0;
	c->registers[Register::R10] = 0;
	c->registers[Register::FLAG] = 0; // TODO: flag values
}

void print(cpu* c)
{
	std::cout << c->registers[Register::R1] << ' ' << c->registers[Register::R2] << ' ' << c->registers[Register::R3] << ' ' << c->registers[Register::R4]
		<< ' ' << c->registers[Register::R5] << ' ' << c->registers[Register::R6] << ' ' << c->registers[Register::R7]
		<< ' ' << c->registers[Register::R8] << ' ' << c->registers[Register::R9] << ' ' << c->registers[Register::R10] << '\n';
}

void execute(cpu* c, std::map <int, instruction> code)
{
	for (int i = 0; i < code.size(); ++i)
	{
		instruction cur = code[i];
		if (cur.opcode == Opcode::MOV)
		{
			cur.is_src_imm ? c->registers[cur.dest_reg] = cur.src_imm_value : c->registers[cur.dest_reg] = c->registers[cur.src_reg];
		}
		if (cur.opcode == Opcode::INC)
		{
			++c->registers[cur.dest_reg];
		}
		if (cur.opcode == Opcode::DEC)
		{
			--c->registers[cur.dest_reg];
		}
		if (cur.opcode == Opcode::ADD)
		{
			cur.is_src_imm ? c->registers[cur.dest_reg] += cur.src_imm_value : c->registers[cur.dest_reg] += c->registers[cur.src_reg];
		}
		if (cur.opcode == Opcode::SUB)
		{
			cur.is_src_imm ? c->registers[cur.dest_reg] -= cur.src_imm_value : c->registers[cur.dest_reg] -= c->registers[cur.src_reg];
		}
		if (cur.opcode == Opcode::MUL)
		{
			cur.is_src_imm ? c->registers[cur.dest_reg] *= cur.src_imm_value : c->registers[cur.dest_reg] *= c->registers[cur.src_reg];
		}
		if (cur.opcode == Opcode::DIV)
		{
			cur.is_src_imm ? c->registers[cur.dest_reg] /= cur.src_imm_value : c->registers[cur.dest_reg] /= c->registers[cur.src_reg];
		}
		if (cur.opcode == Opcode::CMP)
		{
			if (cur.is_src_imm)
			{
				if (c->registers[cur.dest_reg] > cur.src_imm_value)
					c->registers[Register::FLAG] = 1;
				else if (c->registers[cur.dest_reg] < cur.src_imm_value)
					c->registers[Register::FLAG] = -1;
				else
					c->registers[Register::FLAG] = 0;
			}
			else
			{
				if (c->registers[cur.dest_reg] > c->registers[cur.src_reg])
					c->registers[Register::FLAG] = 1;
				else if (c->registers[cur.dest_reg] < c->registers[cur.src_reg])
					c->registers[Register::FLAG] = -1;
				else
					c->registers[Register::FLAG] = 0;
			}
		}

		if (cur.opcode == Opcode::JL)
		{
			if (c->registers[Register::FLAG] == -1)
			{
				i = cur.target - 1;
			}
		}
		if (cur.opcode == Opcode::JG)
		{
			if (c->registers[Register::FLAG] == 1)
			{
				i = cur.target - 1;
			}
		}
		if (cur.opcode == Opcode::JE)
		{
			if (c->registers[Register::FLAG] == 0)
			{
				i = cur.target - 1;
			}
		}
		if (cur.opcode == Opcode::JMP)
		{
			i = cur.target - 1;
		}
		if (cur.opcode == Opcode::AND)
		{
			int first = c->registers[cur.dest_reg];
			int second = 0;

			cur.is_src_imm ? second = cur.src_imm_value : second = c->registers[cur.src_reg];

			int number = 0;

			int bitUpper = 1;
			bool areBit = false;
			for (int i = 1; i <= sizeof(int) * 8; ++i)
			{
				areBit = ((first << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1) & ((second << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1);
				if (areBit)
				{
					number += bitUpper;
				}
				bitUpper *= 2;
			}

			c->registers[cur.dest_reg] = number;
		}
		if (cur.opcode == Opcode::OR)
		{
			int first = c->registers[cur.dest_reg];
			int second = 0;

			cur.is_src_imm ? second = cur.src_imm_value : second = c->registers[cur.src_reg];

			int number = 0;

			int bitUpper = 1;
			bool areBit = false;
			for (int i = 1; i <= sizeof(int) * 8; ++i)
			{
				areBit = ((first << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1) | ((second << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1);
				if (areBit)
				{
					number += bitUpper;
				}
				bitUpper *= 2;
			}

			c->registers[cur.dest_reg] = number;
		}
		if (cur.opcode == Opcode::XOR)
		{
			int first = c->registers[cur.dest_reg];
			int second = 0;

			cur.is_src_imm ? second = cur.src_imm_value : second = c->registers[cur.src_reg];

			int number = 0;

			int bitUpper = 1;
			bool areBit = false;
			for (int i = 1; i <= sizeof(int) * 8; ++i)
			{
				areBit = ((first << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1) ^ ((second << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1);
				if (areBit)
				{
					number += bitUpper;
				}
				bitUpper *= 2;
			}

			c->registers[cur.dest_reg] = number;
		}
		if (cur.opcode == Opcode::NOT)
		{
			int first = c->registers[cur.dest_reg];
			int second = 0;

			cur.is_src_imm ? second = cur.src_imm_value : second = c->registers[cur.src_reg];

			int number = 0;

			int bitUpper = 1;
			bool areBit = false;

			int startBit = 1;
			while (!(first >> sizeof(int) * 8 - startBit))
				++startBit;
			--startBit;

			for (int i = 1; i <= sizeof(int) * 8 - startBit; ++i)
			{
				areBit = ((first << sizeof(int) * 8 - i) >> sizeof(int) * 8 - 1) ^ 1;
				if (areBit)
				{
					number += bitUpper;
				}
				bitUpper *= 2;
			}

			c->registers[cur.dest_reg] = number;
		}
	}
}