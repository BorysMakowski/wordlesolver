#pragma once
#include "solver_b.h"

class SolverC : public SolverB
{
public:
	SolverC(std::vector <std::string> _wordList);
	virtual ~SolverC();

	void solve(Game* game);

	std::vector <std::string> propagateReducedWordList();
	bool matchesKnownLetters(std::string word);

private:
	std::string knownLetters;
	std::vector <std::string> reducedWordList;
};


