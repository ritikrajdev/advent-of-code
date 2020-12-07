#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

short int getNumber (const std::string &binaryPosition, char takeUpperHalfCondition, char takeLowerHalfCondition, short int low, short int high);

int main()
{
//	std::fstream inputFile("test.txt"); // Debug
	std::fstream inputFile("input.txt"); // Result
	
	std::string lineFromFile;
	std::vector<short int> seatIDs;

	while (std::getline(inputFile, lineFromFile))
	{
//		std::cout << lineFromFile << std::endl;

		short int row = getNumber(lineFromFile.substr(0,7), 'B', 'F', 0, 127);
		short int col = getNumber(lineFromFile.substr(7,3), 'R', 'L', 0, 7);
		
		short int seatID = (row * 8) + col;

		seatIDs.push_back(seatID);
	}

	std::sort(seatIDs.begin(), seatIDs.end());

	const int seatIDsSize = seatIDs.size();

	for (int i = 0;i < seatIDsSize - 1; i++)
	{
		if (seatIDs[i+1] - seatIDs[i] == 2)
			std::cout << seatIDs[i] + 1 << std::endl;
	}

	return 0;
}

short int getNumber (const std::string &binaryPosition, char takeUpperHalfCondition, char takeLowerHalfCondition, short int low, short int high)
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
