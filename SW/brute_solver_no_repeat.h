#pragma once
#include "solver.h"

class BruteSolverNoRepeat : public Solver
{
public:
	BruteSolverNoRepeat()
	{
		//std::cout << timesWon << " " << timesLost << " " << wordList.at(1) << std::endl;
		std::cout << "BruteSolverNoRepeat constructor called" << std::endl;
	};

	void solve(Game* game)
	{
		int guessNumber = 0;
		while (!game->isFinished() && !game->isWon())
		{
			int randNum = getRandomInt(0, wordList.size() - 1);
			while (wasTried(randNum))
				randNum = getRandomInt(0, wordList.size() - 1);

			//std::cout << game.guess(wordList.at(getRandomInt(0, wordList.size()))) << std::endl;
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