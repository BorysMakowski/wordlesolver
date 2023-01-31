#pragma once
#include "brute_solver_no_repeat.h"

BruteSolverNoRepeat::BruteSolverNoRepeat(std::vector <std::string> _wordList) :Solver(_wordList){};
BruteSolverNoRepeat::~BruteSolverNoRepeat() {};

	void BruteSolverNoRepeat::solve(Game* game)
	{
		for (int i = 0; i < 6; ++i)
			wordListSizes.at(i) += (wordList.size() - i);

		int guessNumber = 0;
		while (!game->isFinished() && !game->isWon())
		{
			int randNum = getRandomInt(0, wordList.size() - 1);
			while (wasTried(randNum))
				randNum = getRandomInt(0, wordList.size() - 1);

			game->guess(wordList.at(randNum));
			guessNumber++;
			triedWords.push_back(randNum);
		}
		triedWords.clear();
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

	bool BruteSolverNoRepeat::wasTried(int in)
	{
		for (auto i : triedWords)
			if (i == in)
				return true;
		return false;
	}
