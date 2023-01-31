#pragma once
#include "game.h"

class Solver
{
public:
	Solver(std::vector <std::string> _wordList);

	virtual ~Solver();

	virtual void solve(Game* game) = 0;

	/*
	// SETTERS, GETTERS
	*/

	int getTimesWon();

	int getTimesLost();

	std::vector<unsigned int> getWordListSizes();

	std::vector<int> getWonAtGuess();

protected:
	int timesWon;
	int timesLost;
	std::vector<unsigned int> wordListSizes;
	std::vector<int> wonAtGuess;
	std::vector <std::string> wordList;

};