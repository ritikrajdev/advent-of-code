#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	int validPassCounter = 0;
	std::ifstream passwordFile("input.txt");
	std::string passwordPattern;

	while (std::getline(passwordFile, passwordPattern))
	{
		std::stringstream passwordPatternStream(passwordPattern);

		int position1, position2;
		char characterToMatch, temp1, temp2;
		std::string password;

		passwordPatternStream >> position1 >> temp1 >> position2 >> characterToMatch >> temp2 >> password;

		if (password.length() < position1)
		{
			continue;
		}
		else if (password.length() < position2)
		{
			if(password[position1-1] == characterToMatch)
				validPassCounter++;
		}

		else if ((password[position1-1] == characterToMatch) != (password[position2-1] == characterToMatch))
		{
			validPassCounter++;
		}
	}

	std::cout << validPassCounter << std::endl;
}
