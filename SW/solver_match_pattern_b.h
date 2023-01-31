#pragma once
#include "solver_match_pattern_a.h"

bool customSorter(std::string lhs, std::string rhs);

class SolverMatchPatternB : public SolverMatchPatternA
{
public:
	SolverMatchPatternB(std::vector <std::string> _wordList);
	virtual ~SolverMatchPatternB();

	void solve(Game* game);

	std::vector <std::string> applyPattern();
	bool uniqueLetters(std::string word);
};


