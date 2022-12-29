#pragma once
#include "solver.h"
/// <summary>
/// takes letter absence and presencce into account
/// </summary>

class SolverB : public Solver
{
public:
	SolverB()
	{
		////std::cout << "SolverB constructor called" << std::endl;
	};

	void solve(Game* game)
	{
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
			for (int i = 0; i < 6; ++i)
			{
				if (prevResult[i] == '-')
				{
					if (!(std::find(lettersBlackList.begin(), lettersBlackList.end(), prevGuess[i]) != lettersBlackList.end()))
						lettersBlackList.push_back(prevGuess[i]);
				}
				else
				{
					if (!(std::find(lettersWhiteList.begin(), lettersWhiteList.end(), prevGuess[i]) != lettersWhiteList.end()))
						lettersWhiteList.push_back(prevGuess[i]);
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
				reducedWordList = propagateWordListConsiderBlackListAndWhiteList();
			std::cout << "wordlist size: " << reducedWordList.size() << std::endl;

			//if (reducedWordList.size()>0)
			//{
				randNum = getRandomInt(0, reducedWordList.size() - 1);
				prevGuess = reducedWordList.at(randNum);
			//}
			prevResult = game->guess(prevGuess);
			std::cout << prevResult << std::endl;		//
			std::cout << prevGuess << std::endl;		   //
		}
		if (game->isWon())
			timesWon++;
		else
			timesLost++;
	}

	/*
	// HELPER FUNCTIONS
	*/

	std::vector <std::string> propagateWordListConsiderBlackListAndWhiteList()
	{
		std::string temp;
		std::vector <std::string> output;
		for (auto i : wordList)
		{
			if (!containsLetterFromBlackList(i) && containsLettersFromWhiteList(i))
			{
				output.push_back(i);
			}

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
	//bool containsLettersFromWhiteList(std::string word)
	//{
	//	int count = 0;
	//	for (int i = 0; i < 6; i++)
	//	{
	//		for (auto j : lettersWhiteList)
	//			if (word[i] == j)
	//				count++;
	//	}
	//	if (count >= lettersWhiteList.size())
	//		return true;
	//	return false;
	//}

	//bool containsLettersFromWhiteList(std::string word)//235/1000, 2035s
	//{
	//	std::vector<int>counts;
	//	for (int i = 0; i < lettersWhiteList.size(); ++i)
	//	{
	//		counts.push_back(0);
	//		for (int j = 0; j < 6; j++)
	//		{
	//			if (word[j] == lettersWhiteList.at(i))
	//			{
	//				counts.at(i)++;
	//			}
	//		}
	//	}
	//	for (auto i : counts)
	//		if (i == 0)
	//			return false;
	//	return true;
	//}

	//bool containsLettersFromWhiteList(std::string word)//19/100, 612s
	//{
	//	for (int i = 0; i < lettersWhiteList.size(); ++i)
	//	{
	//		count = 0;
	//		for (int j = 0; j < 6; j++)
	//		{
	//			if (word[j] == lettersWhiteList.at(i))
	//			{
	//				count++;
	//			}
	//		}
	//		if (count == 0)
	//			return false;
	//	}
	//	return true;
	//}

	bool containsLettersFromWhiteList(std::string word)//16/100, 781s
	{
		counts.clear();
		for (int i = 0; i < lettersWhiteList.size(); ++i)
		{
			counts.push_back(0);
			for (int j = 0; j < 6; j++)
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
	int count;
	std::vector<int>counts;
	std::vector <char> lettersBlackList;
	std::vector <char> lettersWhiteList;
	std::vector <std::string> reducedWordList;
	std::string prevResult = "";
	std::string prevGuess = "";
};


