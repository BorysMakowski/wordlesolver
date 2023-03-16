#pragma once
#include "game.h"

class Solver
{
public:
	Solver(std::vector <std::string> _wordList);

	virtual ~Solver();

	virtual void solve(Game* game) = 0;

	int getTimesWon();

	int getTimesLost();

	std::vector<long long> getWordListSizes();

	std::vector<int> getWonAtGuess();

protected:
	int timesWon;
	int timesLost;
	std::vector<long long> wordListSizes;
	std::vector<int> wonAtGuess;
	std::vector <std::string> wordList;

};