#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

int main()
{
	const int sumTo = 2020;

	std::string numberString;

	std::ifstream myFile("input.txt");
	std::vector<int> numbers;

	while (std::getline(myFile, numberString)) 
	{
		std::stringstream numberStream(numberString);
		int number = 0;

		numberStream >> number;

		numbers.push_back(number);
	}

	const int numbers_length = numbers.size();

	for ( int i = 0 ; i < numbers_length ; i++ )
	{
		for ( int j = i+1 ; j < numbers_length ; j++ )
		{
			if( numbers.at(i) + numbers.at(j) == sumTo )
			{
				std::cout << numbers.at(i) * numbers.at(j) << std::endl;
				break;
			}
		}
	}

	return 0;
}
