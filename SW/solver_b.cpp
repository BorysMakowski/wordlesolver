#include "solver_b.h"

SolverB::SolverB(std::vector <std::string> _wordList) :SolverA(_wordList)
{
	prevResult = "";
	prevGuess = "";
};
SolverB::~SolverB() {};

void SolverB::solve(Game* game)
{
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
				if (!(std::find(lettersWhiteList.begin(), lettersWhiteList.end(), prevGuess[i]) != lettersWhiteList.end()))
					lettersWhiteList.push_back(prevGuess[i]);
			}

		}

		reducedWordList = propagateWordListConsiderBlackListAndWhiteList();
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

std::vector <std::string> SolverB::propagateWordListConsiderBlackListAndWhiteList()
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

bool SolverB::containsLettersFromWhiteList(std::string word)
{
	std::vector<int>counts;
	for (unsigned int i = 0; i < lettersWhiteList.size(); ++i)
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



