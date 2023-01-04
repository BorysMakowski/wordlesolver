#pragma once
#include "solver.h"
/// <summary>
/// takes letter absence, presence and position into account
/// </summary>
/// 


class SolverC : public Solver
{
public:
	SolverC()
	{
		////std::cout << "SolverC constructor called" << std::endl;
	};

	void solve(Game* game)
	{
		knownLetters = "-----";
		reducedWordList = wordList;
		lettersBlackList.clear();
		lettersWhiteList.clear();
		//guess first word at random
		int randNum = getRandomInt(0, reducedWordList.size() - 1);
		prevGuess = reducedWordList.at(randNum);
		prevResult = game->guess(prevGuess);


		//
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "=====" << std::endl;//

		std::cout << game->getSolution() << std::endl;//
		std::cout << "=====" << std::endl;//
		std::cout << prevResult << std::endl;		//
		std::cout << prevGuess << std::endl;		   //
		//
		while (!game->isFinished() && !game->isWon())
		{
			for (int i = 0; i < 5; ++i)
			{
				if (prevResult[i] == '-')
				{
					if (!(std::find(lettersBlackList.begin(), lettersBlackList.end(), prevGuess[i]) != lettersBlackList.end()))
						lettersBlackList.push_back(prevGuess[i]);
				}
				else
				{
					if (prevResult[i] == '+')
					{
						if (!(std::find(lettersWhiteList.begin(), lettersWhiteList.end(), prevGuess[i]) != lettersWhiteList.end()))
							lettersWhiteList.push_back(prevGuess[i]);
					}
					else
					{
						knownLetters[i] = prevGuess[i];
						if (!(std::find(lettersWhiteList.begin(), lettersWhiteList.end(), prevGuess[i]) != lettersWhiteList.end()))
							lettersWhiteList.push_back(prevGuess[i]);
					}

				}

			}

			std::cout << "lettersBlackList: ";
			for (auto i : lettersBlackList)
				std::cout << i;
			std::cout << std::endl;
			std::cout << "lettersWhiteList: ";
			for (auto i : lettersWhiteList)
				std::cout << i;
			std::cout << std::endl;

			//std::cout << "wordlist size: " << reducedWordList.size() << std::endl;
			reducedWordList = propagateReducedWordList();
			std::cout << "wordlist size: " << reducedWordList.size() << std::endl;


			randNum = getRandomInt(0, reducedWordList.size() - 1);
			prevGuess = reducedWordList.at(randNum);
			prevResult = game->guess(prevGuess);
			std::cout << prevResult << std::endl;		//
			std::cout << prevGuess << std::endl;		   //
		}
		if (game->isWon())
			timesWon++;
		else
			timesLost++;


			std::cout << "known letters: " << knownLetters << std::endl;
			for (auto i : reducedWordList)
			{
				std::cout << i;
				std::cout << std::endl;
			}

			std::cout <<"////////////////////////////////////////////////////"<< std::endl;
	}

	/*
	// HELPER FUNCTIONS
	*/

	std::vector <std::string> propagateReducedWordList()
	{
		std::string temp;
		std::vector <std::string> output;
		for (auto i : wordList)
		{
			if (!containsLetterFromBlackList(i) && containsLettersFromWhiteList(i) && matchesKnownLetters(i))
			{
				output.push_back(i);
			}

		}
		return output;
	}

	bool matchesKnownLetters(std::string word)
	{
		for (int i = 0; i < 5; i++)
		{
			if (knownLetters[i] != '-')
			{
				if (word[i] != knownLetters[i])
					return false;
			}
		}
		return true;
	}

	bool containsLetterFromBlackList(std::string word)
	{
		for (int i = 0; i < 5; i++)
		{
			for (auto j : lettersBlackList)
				if (word[i] == j)
					return true;
		}
		return false;
	}

	bool containsLettersFromWhiteList(std::string word)//235/1000, 2035s
	{
		std::vector<int>counts;
		for (int i = 0; i < lettersWhiteList.size(); ++i)
		{
			counts.push_back(0);
			for (int j = 0; j < 5; j++)
			{
				if (word[j] == lettersWhiteList.at(i))
				{
					counts.at(i)++;
				}
			}
		}
		for (auto i : counts)
			if (i == 0)
				return false;
		return true;
	}



private:

	std::string knownLetters = "-----";
	std::vector<int>counts;
	std::vector <char> lettersBlackList;
	std::vector <char> lettersWhiteList;
	std::vector <std::string> reducedWordList;
	std::string prevResult = "";
	std::string prevGuess = "";
};


