#pragma once
#include "solver.h"

bool customSorterAsc(std::string lhs, std::string rhs);

class SolverMatchPatternC : public Solver
{
public:
	SolverMatchPatternC(std::vector <std::string> _wordList);

	virtual ~SolverMatchPatternC();

	void solve(Game* game);

	/*
	// HELPER FUNCTIONS
	*/
	void showPattern();

	void resetPattern();

	std::vector <std::string> applyPattern();

	void removeFromPattern(char letter);

	bool matchesPattern(std::string word);

	bool containsRequiredLetters(std::string word);

	bool uniqueLetters(std::string word);

private:
	std::vector <char> pattern[5];
	std::vector <char> requiredLetters;
	std::string prevResult;
	std::string prevGuess;
	std::vector <std::string> reducedWordList;
};


