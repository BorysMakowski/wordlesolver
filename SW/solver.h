#pragma once
#include "game.h"

class Solver
{
public:
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

protected:
	int timesWon = 0;
	int timesLost = 0;
	std::vector <std::string> wordList = propagateWordList();

};