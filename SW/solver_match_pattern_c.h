#pragma once
#include "solver_match_pattern_a.h"



class SolverMatchPatternC : public SolverMatchPatternA
{
public:
	SolverMatchPatternC(std::vector <std::string> _wordList);
	virtual ~SolverMatchPatternC();

	void solve(Game* game);
	static bool customSorterAsc(std::string lhs, std::string rhs);
};


