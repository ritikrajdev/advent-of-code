#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int main()
{
	std::fstream inputFile("test.txt"); // Debug
//	std::fstream inputFile("input.txt"); // Result
	
	std::string lineFromFile;

	while (std::getline(inputFile, lineFromFile))
	{
		std::cout << lineFromFile << std::endl;
	}

	return 0;
}
