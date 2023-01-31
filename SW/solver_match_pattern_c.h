#pragma once
#include "solver_match_pattern_b.h"

bool customSorterAsc(std::string lhs, std::string rhs);

class SolverMatchPatternC : public SolverMatchPatternB
{
public:
	SolverMatchPatternC(std::vector <std::string> _wordList);
	virtual ~SolverMatchPatternC();

	void solve(Game* game);
};


