#pragma once
#include "solver.h"

class SolverA : public Solver
{
public:
	SolverA(std::vector <std::string> _wordList);
	virtual ~SolverA();

	void solve(Game* game);

	std::vector <std::string> propagateWordListConsiderBlackList();
	bool containsLetterFromBlackList(std::string word);

protected:
	std::vector <char> lettersBlackList;
	std::vector <std::string> reducedWordList;
	std::string prevResult;
	std::string prevGuess;
};


