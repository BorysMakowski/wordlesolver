#pragma once
#include "solver.h"
/// <summary>
/// takes only letter absence into account
/// </summary>

class SolverA : public Solver
{
public:
	SolverA()
	{
		////std::cout << "SolverA constructor called" << std::endl;
	};

	void solve(Game* game)
	{
		reducedWordList = wordList;
		lettersBlackList.clear();
		//guess first word at random
		int randNum = getRandomInt(0, reducedWordList.size() - 1);
		prevGuess = reducedWordList.at(randNum);
		prevResult = game->guess(prevGuess);
		//
		//std::cout << "=====" << std::endl;//
		//std::cout << game->getSolution() << std::endl;//
		//std::cout << "=====" << std::endl;//
		//std::cout << prevResult << std::endl;		//
		//std::cout << prevGuess << std::endl;		   //
		//
		while (!game->isFinished() && !game->isWon())
		{
			for (int i = 0; i < 6; ++i)
			{
				if (prevResult[i] == '-')
					lettersBlackList.push_back(prevGuess[i]);
			}

			//for (auto i : lettersBlackList)
			//	std::cout << i;
			////std::cout << std::endl;

			////std::cout << "wordlist size: " << reducedWordList.size() << std::endl;
			reducedWordList = propagateWordListConsiderBlacklist();
			////std::cout << "wordlist size: " << reducedWordList.size() << std::endl;

			if (reducedWordList.size() > 0)
			{
				randNum = getRandomInt(0, reducedWordList.size() - 1);
				prevGuess = reducedWordList.at(randNum);
			}
			prevResult = game->guess(prevGuess);
			//std::cout << prevResult << std::endl;		//
			//std::cout << prevGuess << std::endl;		   //
		}
		if (game->isWon())
			timesWon++;
		else
			timesLost++;
	}

	/*
	// HELPER FUNCTIONS
	*/

	std::vector <std::string> propagateWordListConsiderBlacklist()
	{
		std::string temp;
		std::vector <std::string> output;
			for (auto i: wordList)
			{
				if (!containsLetterFromBlackList(i))
					output.push_back(i);
			}
		return output;
	}

	bool containsLetterFromBlackList(std::string word)
	{
		for (int i = 0; i < 6; i++)
		{
			for (auto j : lettersBlackList)
				if (word[i] == j)
					return true;
		}
		return false;

	}

private:
	std::vector <char> lettersBlackList;
	std::vector <std::string> reducedWordList;
	std::string prevResult = "";
	std::string prevGuess = "";
};


