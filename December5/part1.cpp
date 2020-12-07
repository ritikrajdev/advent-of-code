#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int getNumber (const std::string &binaryPosition, char takeUpperHalfCondition, char takeLowerHalfCondition, int low, int high);

int main()
{
//	std::fstream inputFile("test.txt"); // Debug
	std::fstream inputFile("input.txt"); // Result
	
	std::string lineFromFile;

	int maxSeatID = 0;

	while (std::getline(inputFile, lineFromFile))
	{
//		std::cout << lineFromFile << std::endl;

		int row = getNumber(lineFromFile.substr(0,7), 'B', 'F', 0, 127);
		int col = getNumber(lineFromFile.substr(7,3), 'R', 'L', 0, 7);
		
		int seatID = (row * 8) + col;

		if (maxSeatID < seatID)
			maxSeatID = seatID;
	}

	std::cout << maxSeatID << std::endl;

	return 0;
}

int getNumber (const std::string &binaryPosition, char takeUpperHalfCondition, char takeLowerHalfCondition, int low, int high)
{
	// lettered String.

	for (auto i: binaryPosition)
	{
		if (i == takeLowerHalfCondition)
			high = (low + high) / 2;

		if (i == takeUpperHalfCondition)
			low = ((low + high) / 2) + 1;
	}

	return low;
}
