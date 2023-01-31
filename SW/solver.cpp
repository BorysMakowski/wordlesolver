#include "solver.h"


Solver::Solver(std::vector <std::string> _wordList)
{

	timesWon = 0;
	timesLost = 0;
	wordListSizes = { 0,0,0,0,0,0,0 };
	wonAtGuess = { 0,0,0,0,0,0,0 };
	wordList = _wordList;
};

Solver::~Solver() {};

/*
// SETTERS, GETTERS
*/

int Solver::getTimesWon()
{
	return timesWon;
}

int Solver::getTimesLost()
{
	return timesLost;
}

std::vector<unsigned int> Solver::getWordListSizes()
{
	return wordListSizes;
}

std::vector<int> Solver::getWonAtGuess()
{
	return wonAtGuess;
}

