#pragma once
#include "brute_solver.h"

class BruteSolverNoRepeat : public BruteSolver
{
public:
	BruteSolverNoRepeat(std::vector <std::string> _wordList);
	virtual ~BruteSolverNoRepeat();

	void solve(Game* game);

	/*
	// HELPER FUNCTIONS
	*/

	bool wasTried(int wordNum);

private:
	std::vector <int> triedWords;

};