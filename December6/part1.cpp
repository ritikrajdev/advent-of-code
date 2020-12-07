#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int getAnswersByTeam (std::vector<std::string> &teamAnswers);

int main()
{
//	std::fstream inputFile("test.txt"); // Debug
	std::fstream inputFile("input.txt"); // Result
	
	std::string lineFromFile;

	std::vector<std::string> teamAnswers;
	int sumOfCountOfAnswers = 0;

	while (std::getline(inputFile, lineFromFile))
	{
		if (lineFromFile == "")
		{
			std::cout << getAnswersByTeam(teamAnswers) << std::endl; // Debug
			sumOfCountOfAnswers += getAnswersByTeam(teamAnswers);
			teamAnswers.clear();
		}
		else 
		{
			teamAnswers.push_back(lineFromFile);
		}
	}

	std::cout << sumOfCountOfAnswers << std::endl;

	return 0;
}

int getAnswersByTeam (std::vector<std::string> &teamAnswers)
{
	std::string answers = "";
	short int countOfAnswers = 0;

	for (auto playerAnswer: teamAnswers)
	{
		for (char answer: playerAnswer)
		{
			if (answers.find(answer) == std::string::npos)
			{
				countOfAnswers++;
				answers += answer;
			}
		}
	}

	return countOfAnswers;
}
