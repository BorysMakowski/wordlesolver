#pragma once
#include "solver.h"

class BruteSolver : public Solver
{
public:
	BruteSolver(std::vector <std::string> _wordList);
	virtual ~BruteSolver();

	void solve(Game* game);
};