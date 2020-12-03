#include <fstream>
#include <iostream>
#include <string>

int main()
{
	std::ifstream inputFile("input.txt");
	std::string line;

	int rightPosition = 0, treeCounter = 0;

	while (std::getline(inputFile, line))
	{
		const int lineLength = line.length();
		const char characterAtDesiredPosition = line[(rightPosition % lineLength)];

		if (characterAtDesiredPosition == '#')
		{
			treeCounter++;
		}

		rightPosition += 3;

	}

	std::cout << treeCounter << std::endl;
	return 0;
}
