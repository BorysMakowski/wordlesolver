#pragma once
#include "game.h"

class Solver
{
public:
	Solver(std::vector <std::string> _wordList)
	{
		wordList = _wordList;
	};

	virtual ~Solver() {};

	virtual void solve(Game* game) = 0;

	/*
	// SETTERS, GETTERS
	*/

	int getTimesWon()
	{
		return timesWon;
	}

	int getTimesLost()
	{
		return timesLost;
	}

	std::vector<int> getWordListSizes()
	{
		return wordListSizes;
	}

	std::vector<int> getWonAtGuess()
	{
		return wonAtGuess;
	}

protected:
	int timesWon = 0;
	int timesLost = 0;
	std::vector<int> wordListSizes{ 0,0,0,0,0,0,0 };
	std::vector<int> wonAtGuess{ 0,0,0,0,0,0,0 };
	std::vector <std::string> wordList;

};