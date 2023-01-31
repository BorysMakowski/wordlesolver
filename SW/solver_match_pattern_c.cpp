#include "solver_match_pattern_c.h"

bool customSorterAsc(std::string lhs, std::string rhs)
{
	std::vector <char> mostCommonLetters{ 'a','e','s','o','r','i','l','t','n','u','d','c','y','m','p','h','b','g','k','f','w','v','z','j','x','q' };
	std::reverse(mostCommonLetters.begin(), mostCommonLetters.end());
	std::set<int> lhsScore;
	std::set<int> rhsScore;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (lhs[i] == mostCommonLetters.at(j))
				lhsScore.insert(26 - j);
			if (rhs[i] == mostCommonLetters.at(j))
				rhsScore.insert(26 - j);
		}
	}
	int lhsSum = std::accumulate(lhsScore.begin(), lhsScore.end(), 0);
	int rhsSum = std::accumulate(rhsScore.begin(), rhsScore.end(), 0);
	return (lhsSum > rhsSum);
}


SolverMatchPatternC::SolverMatchPatternC(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		prevResult = "";
		prevGuess = "";
	};
SolverMatchPatternC::~SolverMatchPatternC() {};


	void SolverMatchPatternC::solve(Game* game)
	{
		requiredLetters.clear();
		resetPattern();

		reducedWordList = wordList;
		wordListSizes.at(0) += reducedWordList.size();

		prevGuess = *std::min_element(reducedWordList.begin(), reducedWordList.end(), customSorterAsc);

		prevResult = game->guess(prevGuess);
		int guessNumber = 1;

		while (!game->isFinished() && !game->isWon())
		{
			for (int i = 0; i < 5; ++i)
			{
				if (prevResult[i] == '-')
				{
					removeFromPattern(prevGuess[i]);
				}
				else
				{
					if (prevResult[i] == '+')
					{
						if (!(std::find(requiredLetters.begin(), requiredLetters.end(), prevGuess[i]) != requiredLetters.end()))
							requiredLetters.push_back(prevGuess[i]);
						pattern[i].erase(std::remove(pattern[i].begin(), pattern[i].end(), prevGuess[i]), pattern[i].end());
					}
					else
					{
						pattern[i].clear();
						pattern[i].push_back(prevResult[i]);
					}

				}

			}

			reducedWordList = applyPattern();
			wordListSizes.at(guessNumber) += reducedWordList.size();

			prevGuess = *std::min_element(reducedWordList.begin(), reducedWordList.end(), customSorterAsc);

			prevResult = game->guess(prevGuess);
			guessNumber++;
		}
		if (game->isWon())
		{
			timesWon++;
			wonAtGuess.at(guessNumber)++;
		}
		else
			timesLost++;
	}

	/*
	// HELPER FUNCTIONS
	*/
	void SolverMatchPatternC::showPattern()
	{
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "[" << i << "]: ";
			for (auto j : pattern[i])
				std::cout << j;
			std::cout << std::endl;
		}
	}

	void SolverMatchPatternC::resetPattern()
	{
		for (int i = 0; i < 5; ++i)
		{
			pattern[i].clear();
			for (int j = 97; j < 123; ++j)
				pattern[i].push_back((char)j);
		}
	}

	std::vector <std::string> SolverMatchPatternC::applyPattern()
	{
		std::vector <std::string> output;
		for (auto i : wordList)
		{
			if (matchesPattern(i) && containsRequiredLetters(i))
			{
				output.push_back(i);
			}
		}
		return output;
	}

	void SolverMatchPatternC::removeFromPattern(char letter)
	{
		for (int i = 0; i < 5; ++i)
			pattern[i].erase(std::remove(pattern[i].begin(), pattern[i].end(), letter), pattern[i].end());
	}

	bool SolverMatchPatternC::matchesPattern(std::string word)
	{

		for (int i = 0; i < 5; ++i)
		{
			if (!(std::find(pattern[i].begin(), pattern[i].end(), word[i]) != pattern[i].end()))
				return false;
		}

		return true;
	}

	bool SolverMatchPatternC::containsRequiredLetters(std::string word)
	{
		std::vector<int>counts;
		for (unsigned int i = 0; i < requiredLetters.size(); ++i)
		{
			counts.push_back(0);
			for (int j = 0; j < 5; j++)
			{
				if (word[j] == requiredLetters.at(i))
				{
					counts.at(i)++;
				}
			}
		}
		for (auto i : counts)
			if (i == 0)
				return false;
		return true;
	}

	bool SolverMatchPatternC::uniqueLetters(std::string word)
	{
		std::set<char> wordSet;
		for (auto i : word)
			wordSet.insert(i);
		return wordSet.size() == word.size();
	}




