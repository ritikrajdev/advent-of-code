#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

int getCommonAnswersByTeam (std::vector<std::string> &teamAnswers);

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
//			std::cout << getCommonAnswersByTeam(teamAnswers) << std::endl; // Debug
			sumOfCountOfAnswers += getCommonAnswersByTeam(teamAnswers);
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

int getCommonAnswersByTeam (std::vector<std::string> &teamAnswers)
{
	short int countOfCommonAnswers = 0;

	for (auto answer: teamAnswers[0])
	{

		int sizeOfVector = teamAnswers.size();
		bool hasAnswer = false;

		for (int i = 0; i < sizeOfVector ; i++)
		{
			if (teamAnswers[i].find(answer) != std::string::npos)
				hasAnswer = true;
			else
			{
				hasAnswer = false;
				break;
			}
		}

		if (hasAnswer)
			countOfCommonAnswers++;
	}

	return countOfCommonAnswers;
}
