#pragma once
#include "solver_a.h"

class SolverB : public SolverA
{
public:
	SolverB(std::vector <std::string> _wordList);
	virtual ~SolverB();

	void solve(Game* game);

	std::vector <std::string> propagateWordListConsiderBlackListAndWhiteList();
	//bool containsLetterFromBlackList(std::string word);
	bool containsLettersFromWhiteList(std::string word);

private:
	std::vector<int> counts;
	//std::vector <char> lettersBlackList;
	std::vector <char> lettersWhiteList;
	//std::vector <std::string> reducedWordList;
	//std::string prevResult;
	//std::string prevGuess;
};


