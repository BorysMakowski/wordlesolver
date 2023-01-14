#pragma once
#include "solver.h"

class BruteSolverNoRepeat : public Solver
{
public:
	BruteSolverNoRepeat(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		//std::cout << "BruteSolverNoRepeat constructor called" << std::endl;
	};
	virtual ~BruteSolverNoRepeat() {};

	void solve(Game* game)
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

	bool wasTried(int in)
	{
		for (auto i : triedWords)
			if (i == in)
				return true;
		return false;
	}

private:
	std::vector <int> triedWords;

};