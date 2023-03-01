#pragma once
#include "solver_match_pattern_a.h"


class SolverMatchPatternB : public SolverMatchPatternA
{
public:
	SolverMatchPatternB(std::vector <std::string> _wordList);
	virtual ~SolverMatchPatternB();

	void solve(Game* game);
	static bool customSorter(std::string lhs, std::string rhs);
	/*bool uniqueLetters(std::string word);*/
};


