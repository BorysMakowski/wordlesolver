#pragma once
#include "solver.h"
/// <summary>
/// takes only letter absence into account
/// </summary>

class SolverA : public Solver
{
public:
	SolverA(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		//std::cout << "SolverA constructor called" << std::endl;
	};
	virtual ~SolverA() {};


	void solve(Game* game)
	{
		reducedWordList = wordList;
		wordListSizes.at(0) += reducedWordList.size();
		lettersBlackList.clear();
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
					lettersBlackList.push_back(prevGuess[i]);
			}

			reducedWordList = propagateWordListConsiderBlacklist();
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

	std::vector <std::string> propagateWordListConsiderBlacklist()
	{
		std::string temp;
		std::vector <std::string> output;
		for (auto i : wordList)
		{
			if (!containsLetterFromBlackList(i))
				output.push_back(i);
		}
		return output;
	}

	bool containsLetterFromBlackList(std::string word)
	{
		for (int i = 0; i < 5; i++)
		{
			for (auto j : lettersBlackList)
				if (word[i] == j)
					return true;
		}
		return false;
	}

private:
	std::vector <char> lettersBlackList;
	std::vector <std::string> reducedWordList;
	std::string prevResult = "";
	std::string prevGuess = "";
};


