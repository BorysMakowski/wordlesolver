#pragma once
#include "solver.h"
/// <summary>
/// takes letter absence, presence and position into account
/// </summary>
/// 


class SolverMatchPatternA : public Solver
{
public:
	SolverMatchPatternA(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		//std::cout << "SolverMatchPatternA constructor called" << std::endl;
	};
	virtual ~SolverMatchPatternA() {};


	void solve(Game* game)
	{
		requiredLetters.clear();
		resetPattern();

		reducedWordList = wordList;
		wordListSizes.at(0) += reducedWordList.size();
		//guess first word at random
		int randNum = getRandomInt(0, reducedWordList.size() - 1);
		prevGuess = reducedWordList.at(randNum);
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

			randNum = getRandomInt(0, reducedWordList.size() - 1);
			prevGuess = reducedWordList.at(randNum);
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

	void showPattern()
	{
		for (int i = 0; i < 5; ++i)
		{
			std::cout << "[" << i << "]: ";
			for (auto j : pattern[i])
				std::cout << j;
			std::cout << std::endl;
		}
	}

	void resetPattern()
	{
		for (int i = 0; i < 5; ++i)
		{
			pattern[i].clear();
			for (int j = 97; j < 123; ++j)
				pattern[i].push_back((char)j);
		}
	}

	std::vector <std::string> applyPattern()
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

	void removeFromPattern(char letter)
	{
		for (int i = 0; i < 5; ++i)
			pattern[i].erase(std::remove(pattern[i].begin(), pattern[i].end(), letter), pattern[i].end());
	}

	bool matchesPattern(std::string word)
	{

		for (int i = 0; i < 5; ++i)
		{
			if (!(std::find(pattern[i].begin(), pattern[i].end(), word[i]) != pattern[i].end()))
				return false;
		}

		return true;
	}

	bool containsRequiredLetters(std::string word)
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

private:
	std::vector <char> pattern[5];
	std::vector <char> requiredLetters;
	std::string prevResult = "";
	std::string prevGuess = "";
	std::vector <std::string> reducedWordList;
};


