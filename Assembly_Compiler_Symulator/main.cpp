#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "cpu.h"

instruction parse(const std::string&);
std::map <std::string, int> f_lables();
std::vector <std::string> split(const std::string&);
int stringToInt(std::string);
std::string toLowerCase(const std::string&);

std::map <std::string, int> lables = f_lables();

int main()
{
	cpu myCpu;
	init_cpu(&myCpu);
	
	std::string myFile = "Assembler.txt";

	std::fstream fs;
	fs.open(myFile, std::fstream::in | std::fstream::out | std::fstream::app);

	std::string msg;
	std::map <int, instruction> code;

	for (int i = 0; i < code.size(); ++i)
		instruction ins = code[i];

	if (!fs.is_open())
	{
		std::cout << "File is not open" << std::endl;
	}
	else
	{
		std::string msg;
		for (int lineNumber = 0; !(fs.eof()); ++lineNumber)
		{
			msg = "";
			std::getline(fs, msg);
			code[lineNumber] = parse(msg);
		}
	}

	execute(&myCpu, code);

	print(&myCpu);

	return 0;
}

instruction parse(const std::string& line)
{
	auto words = split(line);
	instruction ins{};

	if (toLowerCase(words[0]) == "mov")
	{
		ins.opcode = Opcode::MOV;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "inc")
	{
		ins.opcode = Opcode::INC;
		ins.dest_reg = string_to_register(words[1]);
	}
	if (toLowerCase(words[0]) == "dec")
	{
		ins.opcode = Opcode::DEC;
		ins.dest_reg = string_to_register(words[1]);
	}
	if (toLowerCase(words[0]) == "add")
	{
		ins.opcode = Opcode::ADD;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "sub")
	{
		ins.opcode = Opcode::SUB;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "mul")
	{
		ins.opcode = Opcode::MUL;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "div")
	{
		ins.opcode = Opcode::DIV;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "cmp")
	{
		ins.opcode = Opcode::CMP;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "jl")
	{
		ins.opcode = Opcode::JL;
		ins.target = lables[words[1]];
	}
	if (toLowerCase(words[0]) == "jg")
	{
		ins.opcode = Opcode::JG;
		ins.target = lables[words[1]];
	}
	if (toLowerCase(words[0]) == "je")
	{
		ins.opcode = Opcode::JE;
		ins.target = lables[words[1]];
	}
	if (toLowerCase(words[0]) == "jmp")
	{
		ins.opcode = Opcode::JMP;
		ins.target = lables[words[1]];
	}
	if (toLowerCase(words[0]) == "and")
	{
		ins.opcode = Opcode::AND;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "or")
	{
		ins.opcode = Opcode::OR;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "xor")
	{
		ins.opcode = Opcode::XOR;
		ins.dest_reg = string_to_register(words[1]);

		if ('0' <= words[2][0] && words[2][0] <= '9')
			ins.is_src_imm = true;

		if (ins.is_src_imm)
			ins.src_imm_value = stringToInt(words[2]);
		else
			ins.src_reg = string_to_register(words[2]);
	}
	if (toLowerCase(words[0]) == "not")
	{
		ins.opcode = Opcode::NOT;
		ins.dest_reg = string_to_register(words[1]);
	}

	return ins;
}

std::map <std::string, int> f_lables()
{
	std::string myFile = "Assembler.txt";

	std::fstream fs;
	fs.open(myFile, std::fstream::in | std::fstream::out | std::fstream::app);

	std::string msg;
	std::map <std::string, int> lables;

	if (!fs.is_open())
	{
		std::cout << "File is not open" << std::endl;
	}
	else
	{
		for (int lineNumber = 0; !(fs.eof()); ++lineNumber)
		{
			msg = "";
			std::getline(fs, msg);

			bool lable = false;
			for (int i = 0; i < msg.size(); ++i)
				if (msg[i] == ':')
					lable = true;

			if (lable)
			{
				std::vector <std::string> loopLineWords = split(msg);
				std::string loopName = loopLineWords[0];
				for (int i = 0; i < loopName.size(); ++i)
					if (loopName[i] == ':')
						loopName.erase(i, 1);

				lables[loopName] = lineNumber + 1;
			}
		}
	}

	fs.close();

	return lables;
}

std::vector <std::string> split(const std::string& line)
{
	std::string word;
	std::vector <std::string> words;
	bool OnlyTab = true;

	for (int i = 0; i < line.size(); ++i)
	{
		word = "";

		for (;i < line.size() && line[i] != ' ' && line[i] != ','; ++i)
		{
			word.push_back(line[i]);
			OnlyTab = false;
		}

		if (word != "")
			words.push_back(word);
	}

	if (OnlyTab)
	{
		words.push_back("tabLine");
		return words;
	}
	else
		return words;
}

int stringToInt(std::string f)
{
	for (int i = 0; i < f.size();)
	{
		if (f[i] < '0' || '9' < f[i])
		{
			f.erase(i, 1);
		}
		else
			++i;
	}

	int num = 0;
	size_t size = f.size();
	--size;

	int k = 1;

	while (size > 0)
	{
		num += k * (f[size] - '0');
		k *= 10;
		--size;
	}

	num += k * (f[0] - '0');

	return num;
}

std::string toLowerCase(const std::string& str)
{
	std::string strCpy = str;

	for (int i = 0; i < strCpy.size(); ++i)
		if ('A' <= strCpy[i] && strCpy[i] <= 'Z')
			strCpy[i] += 32;

	return strCpy;
}