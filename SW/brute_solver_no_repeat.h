#pragma once
#include "solver.h"

class BruteSolverNoRepeat : public Solver
{
public:
	BruteSolverNoRepeat(std::vector <std::string> _wordList);
	virtual ~BruteSolverNoRepeat();

	void solve(Game* game);

	/*
	// HELPER FUNCTIONS
	*/

	bool wasTried(int in);

private:
	std::vector <int> triedWords;

};