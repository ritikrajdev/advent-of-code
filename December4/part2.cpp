#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

inline bool findSubStr(const std::string &findFrom, std::string toFind)
{
	return (findFrom.find(toFind) != std::string::npos);
}

std::string getField(const std::string &findFrom,std::string fieldToGet)
{
	int index = findFrom.find(fieldToGet + ":");
	std::string field = "";
	while (findFrom[index] != ' ')
	{
		field += findFrom[index];
		index++;
	}

	field.erase(0,4);

	return field;
}

bool isValidByr(std::string byrString)
{
	std::stringstream byrStream(byrString);
	int byr;
	byrStream >> byr;

	if (byr >= 1920 && byr <= 2020)
		return true;

	return false;
}

bool isValidIyr(std::string IyrString)
{
	std::stringstream IyrStream(IyrString);
	int Iyr;
	IyrStream >> Iyr;

	if (Iyr >= 2010 && Iyr <= 2020)
		return true;

	return false;
}

bool isValidEyr(std::string eyrString)
{
	std::stringstream eyrStream(eyrString);
	int eyr;
	eyrStream >> eyr;

	if (eyr >= 2020 && eyr <= 2030)
		return true;

	return false;
}

bool isValidEcl(std::string ecl)
{
	const std::string eyeColor[] = {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};

	for (std::string i:eyeColor)
	{
		if (i == ecl)
			return true;
	}
	return false;
	
}

bool isValidHgt(std::string hgt)
{
	if (hgt.substr(hgt.size() - 2) == "in")
	{
		//Inches
		hgt.erase(hgt.length() - 2);
		std::stringstream hgtStream(hgt);
		int hgtInt = 0;
		hgtStream >> hgtInt;

		if (hgtInt >= 59 && hgtInt <= 76) return true;
		else return false;
	}
	else if (hgt.substr(hgt.size() - 2) == "cm")
	{
		//cms

		hgt.erase(hgt.length() - 2);
		std::stringstream hgtStream(hgt);
		int hgtInt = 0;
		hgtStream >> hgtInt;

		if (hgtInt >= 150 && hgtInt <= 193) return true;
		else return false;
	}
	else
	{
		return false;
	}
}

bool isValidHcl(std::string hcl)
{
	if (hcl.length() != 7) return false;

	if (hcl[0] == '#')
	{
		hcl.erase(0,1);
		for (char i : hcl)
		{
			if ((i >= 'a' && i <= 'f') || (i >= '0' && i <= '9'))
			{
				continue;
			}
			else return false;
		}
		return true;
	}

	else 
	{
		return false;
	}
}

bool isValidPid(std::string pid)
{
	return pid.length() == 9;
}

bool isValid(std::string passPortFields)
{
	if (isValidByr(getField(passPortFields, "byr")) &&
		isValidEyr(getField(passPortFields, "eyr"))	&&
		isValidIyr(getField(passPortFields, "iyr")) &&
		isValidHcl(getField(passPortFields, "hcl")) &&
		isValidHgt(getField(passPortFields, "hgt")) &&
		isValidPid(getField(passPortFields, "pid")) &&
		isValidEcl(getField(passPortFields, "ecl")))
		return true;

	return false;
}


int main()
{
//	std::ifstream inputFile("test.txt");
	std::ifstream inputFile("input.txt");

	char c='\0', prevC='\0';
	std::string passPortFields = "";

	int validCounter = 0;

	while (inputFile.get(c))
	{
		if (c == '\n' && prevC != '\n')
			passPortFields += " ";
		else if ((c == '\n' && prevC == '\n'))
		{
//			std::cout << passPortFields << std::endl;

			if (findSubStr(passPortFields, "byr:") &&
				findSubStr(passPortFields, "iyr:") &&
				findSubStr(passPortFields, "eyr:") &&
				findSubStr(passPortFields, "hgt:") &&
				findSubStr(passPortFields, "hcl:") &&
				findSubStr(passPortFields, "ecl:") &&
				findSubStr(passPortFields, "pid:"))
			{
				if (isValid(passPortFields))
					validCounter++;

			}

			passPortFields = "";
		}
		else 
		{
			passPortFields += c;
		}

		prevC = c;
	}

	std::cout << validCounter << std::endl;
}
