#pragma once
#include "solver.h"

class SolverC : public Solver
{
public:
	SolverC(std::vector <std::string> _wordList);
	virtual ~SolverC();

	void solve(Game* game);

	std::vector <std::string> propagateReducedWordList();
	bool matchesKnownLetters(std::string word);
	bool containsLetterFromBlackList(std::string word);
	bool containsLettersFromWhiteList(std::string word);

private:
	std::string knownLetters;
	std::vector<int>counts;
	std::vector <char> lettersBlackList;
	std::vector <char> lettersWhiteList;
	std::vector <std::string> reducedWordList;
	std::string prevResult;
	std::string prevGuess;
};


