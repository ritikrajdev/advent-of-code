#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


class Solution {
public:
    const int sumTo = 2020;
    std::vector<int> numbers;
    int numbers_length, numFactors;


    int solve (int startFrom = 0, int previousSum = 0, int depthCount = 1)
    { 
        for (int i = startFrom ; i < numbers_length ; i++)
        {
            if (depthCount == numFactors)
            {
                if (previousSum + numbers.at(i) == sumTo)
                {
                    return numbers.at(i);
                }
            }

            else if (depthCount < numFactors)
            {
                int productOfNumbers = solve(startFrom + 1, previousSum + numbers.at(i), depthCount+1);

                if (productOfNumbers > 0){
                    productOfNumbers *= numbers.at(i);

                    return productOfNumbers;
                }
            }
        }
        return 0;
    }
};


int main()
{
    Solution solution;
    
    std::cout << "Enter no. of integers You wanna Find : ";
	std::cin >> solution.numFactors;

	std::ifstream myFile("input.txt");
    std::string numberString;

	while (std::getline(myFile, numberString)) 
	{
		std::stringstream numberStream(numberString);
		int number = 0;

		numberStream >> number;

		solution.numbers.push_back(number);
	}

	solution.numbers_length = solution.numbers.size();

	std::cout << solution.solve();

	return 0;
}
