#include <fstream>
#include <iostream>
#include <string>

int solve (const std::string fileName, int rightSlope = 1, int downSlope = 1)
{
	std::ifstream inputFile(fileName);
	std::string line;


	int rightPosition = 0, treeCounter = 0, lineCounter = 0;

	while (std::getline(inputFile, line))
	{
		
		if (! (lineCounter % downSlope))
		{

			const int lineLength = line.length();
			const char characterAtDesiredPosition = line[(rightPosition % lineLength)];


			if (characterAtDesiredPosition == '#')
			{
				treeCounter++;
			}

			rightPosition += rightSlope;

		}

		lineCounter++;
	}

	return treeCounter;
}

int main()
{

	long long slope11 = solve("input.txt", 1);
	long long slope31 = solve("input.txt", 3);
	long long slope51 = solve("input.txt", 5);
	long long slope71 = solve("input.txt", 7);
	long long slope12 = solve("input.txt", 1, 2); 

	std::cout << slope12*slope11*slope31*slope51*slope71 << std::endl;

	return 0;
}
