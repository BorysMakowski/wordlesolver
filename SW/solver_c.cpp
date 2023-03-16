#include "solver_c.h"

SolverC::SolverC(std::vector <std::string> _wordList) :SolverB(_wordList)
{
	knownLetters = "-----";
	prevResult = "";
	prevGuess = "";
};
SolverC::~SolverC() {};


void SolverC::solve(Game* game)
{
	knownLetters = "-----";
	reducedWordList = wordList;
	wordListSizes.at(0) += reducedWordList.size();
	lettersBlackList.clear();
	lettersWhiteList.clear();
	int randNum = getRandomInt(0, reducedWordList.size() - 1);
	prevGuess = reducedWordList.at(randNum);
	prevResult = game->guess(prevGuess);
	int guessNumber = 1;

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

		reducedWordList = propagateReducedWordList();
		wordListSizes.at(guessNumber) += reducedWordList.size();


		randNum = getRandomInt(0, reducedWordList.size() - 1);
		prevGuess = reducedWordList.at(randNum);
		prevResult = game->guess(prevGuess);
		guessNumber++;
	}

	if (game->isWon())
	{
		timesWon++;
		wonAtGuess.at(guessNumber)++;
	}
	else
		timesLost++;
}

/*
// HELPER FUNCTIONS
*/

std::vector <std::string> SolverC::propagateReducedWordList()
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

bool SolverC::matchesKnownLetters(std::string word)
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




