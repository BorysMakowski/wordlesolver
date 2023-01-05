#pragma once
#include "solver.h"
/// <summary>
/// takes letter absence, presence and position into account
/// </summary>
/// 

bool customSorter(std::string lhs, std::string rhs)
{
	const std::vector <char> mostCommonLetters{ 'a','e','s','o','r','i','l','t','n','u','d','c','y','m','p','h','b','g','k','f','w','v','z','j','x','q' };
	int lhsScore = 0;
	int rhsScore = 0;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (lhs[i] == mostCommonLetters.at(j))
				lhsScore += (26 - j);
			if (rhs[i] == mostCommonLetters.at(j))
				rhsScore += (26 - j);
		}
	}
	return (lhsScore > rhsScore);
}

class SolverMatchPatternB : public Solver
{
public:
	SolverMatchPatternB()
	{
		////std::cout << "SolverMatchPatternB constructor called" << std::endl;
	};

	void solve(Game* game)
	{
		requiredLetters.clear();
		resetPattern();
		int randNum = 0;
		//showPattern();

		reducedWordList = wordList;
		
		//guess first word as "arose"
		prevGuess = "arose";

		prevResult = game->guess(prevGuess);
		int guessNumber = 1;

		//
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "=====" << std::endl;//

		std::cout << game->getSolution() << std::endl;//
		std::cout << "=====" << std::endl;//
		std::cout << prevResult << std::endl;		//
		std::cout << prevGuess << std::endl;		   //
		//
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
			//showPattern();


			//std::cout << "wordlist size: " << reducedWordList.size() << std::endl;
			reducedWordList = applyPattern();
			std::cout << "wordlist size: " << reducedWordList.size() << std::endl;
			if (guessNumber < 3)
			{
				std::cout << "XXXX" << std::endl;
				std::sort(reducedWordList.begin(), reducedWordList.end(), customSorter);
				randNum = 0;
				while (!uniqueLetters(reducedWordList.at(randNum)))
					randNum++;
			}
			else
			{
				randNum = getRandomInt(0, reducedWordList.size() - 1);
			}
			prevGuess = reducedWordList.at(randNum);
			prevResult = game->guess(prevGuess);
			guessNumber++;
			std::cout << prevResult << std::endl;		//
			std::cout << prevGuess << std::endl;		   //
		}
		if (game->isWon())
			timesWon++;
		else
			timesLost++;


		std::cout << "////////////////////////////////////////////////////" << std::endl;
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
		for (int i = 0; i < requiredLetters.size(); ++i)
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

	bool uniqueLetters(std::string word)
	{
		std::set<char> wordSet;
		for (auto i : word)
			wordSet.insert(i);
		return wordSet.size() == word.size();
	}

private:
	std::vector <char> pattern[5];
	std::vector <char> requiredLetters;

	std::string prevResult = "";
	std::string prevGuess = "";
	std::vector <std::string> reducedWordList;
};


