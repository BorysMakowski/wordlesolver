#pragma once
#include "solver.h"

class BruteSolver : public Solver
{
public:
	BruteSolver(std::vector <std::string> _wordList) :Solver(_wordList)
	{
		//std::cout << "BruteSolver constructor called" << std::endl;
	};
	virtual ~BruteSolver() {};

	void solve(Game* game)
	{
		for (int i = 0; i < 6; ++i)
			wordListSizes.at(i) += wordList.size();
		int guessNumber = 0;
		while (!game->isFinished() && !game->isWon())
		{
			int randNum = getRandomInt(0, wordList.size() - 1);
			game->guess(wordList.at(randNum));
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
};