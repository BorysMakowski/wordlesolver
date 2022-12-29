#pragma once
#include "solver.h"

class BruteSolver : public Solver
{
public:
	BruteSolver()
	{
		std::cout << timesWon << " " << timesLost << " " << wordList.at(1) << std::endl;
		std::cout << "BruteSolver constructor called" << std::endl;
	};

	void solve(Game* game)
	{
		while (!game->isFinished() && !game->isWon())
		{
			int randNum = getRandomInt(0, wordList.size()-1);

			//std::cout << game.guess(wordList.at(getRandomInt(0, wordList.size()))) << std::endl;
			game->guess(wordList.at(randNum));
		}
		if (game->isWon())
			timesWon++;
		else
			timesLost++;
	}
};