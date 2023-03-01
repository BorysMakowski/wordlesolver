#pragma once
#include "solver_a.h"


SolverA::SolverA(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		prevResult = "";
		prevGuess = "";
	};
SolverA::~SolverA() {};


	void SolverA::solve(Game* game)
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

			reducedWordList = propagateWordListConsiderBlackList();
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

	std::vector <std::string> SolverA::propagateWordListConsiderBlackList()
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

	bool SolverA::containsLetterFromBlackList(std::string word)
	{
		for (int i = 0; i < 5; i++)
		{
			for (auto j : lettersBlackList)
				if (word[i] == j)
					return true;
		}
		return false;
	}


