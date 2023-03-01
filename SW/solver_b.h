#pragma once
#include "solver_a.h"

class SolverB : public SolverA
{
public:
	SolverB(std::vector <std::string> _wordList);
	virtual ~SolverB();

	void solve(Game* game);

	std::vector <std::string> propagateWordListConsiderBlackListAndWhiteList();
	bool containsLettersFromWhiteList(std::string word);

protected:
	//std::vector<int> counts;
	std::vector <char> lettersWhiteList;
};


