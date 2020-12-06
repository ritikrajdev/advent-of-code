#include <fstream>
#include <iostream>
#include <ostream>
#include <string>

inline bool findSubStr(const std::string &findFrom, std::string toFind)
{
	return (findFrom.find(toFind) != std::string::npos);
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
