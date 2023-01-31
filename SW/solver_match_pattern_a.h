#pragma once
#include "solver.h"

class SolverMatchPatternA : public Solver
{
public:
	SolverMatchPatternA(std::vector <std::string> _wordList);
	virtual ~SolverMatchPatternA();

	void solve(Game* game);

	void showPattern();
	void resetPattern();
	std::vector <std::string> applyPattern();
	void removeFromPattern(char letter);
	bool matchesPattern(std::string word);
	bool containsRequiredLetters(std::string word);

protected:
	std::vector <char> pattern[5];
	std::vector <char> requiredLetters;
	std::string prevResult;
	std::string prevGuess;
	std::vector <std::string> reducedWordList;
};


