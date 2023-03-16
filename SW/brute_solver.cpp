#include "brute_solver.h"

BruteSolver::BruteSolver(std::vector <std::string> _wordList) :Solver(_wordList) {};
BruteSolver::~BruteSolver() {};

void BruteSolver::solve(Game* game)
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
