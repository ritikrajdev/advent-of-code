#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	int countOfCorrectPasswords = 0;
	std::string passwordPattern = "";

	std::ifstream inputFile("./input.txt");

	
	while (std::getline(inputFile, passwordPattern))
	{

		std::stringstream passwordPatternStream(passwordPattern);

		int min,max;
		char temp1, temp2, characterToMatch;
		std::string password;

		passwordPatternStream >> min >> temp1 >> max >> characterToMatch >> temp2 >> password;
		
		int count = 0;

		for(auto character: password)
		{
			if(character == characterToMatch)
				count += 1;
		}

		if( count >= min && count <= max )
			countOfCorrectPasswords += 1;

	}

	std::cout << countOfCorrectPasswords << std::endl;
}
