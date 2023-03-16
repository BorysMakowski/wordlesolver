#include "solver_match_pattern_c.h"

SolverMatchPatternC::SolverMatchPatternC(std::vector <std::string> _wordList) :SolverMatchPatternA(_wordList)
{
	prevResult = "";
	prevGuess = "";
};
SolverMatchPatternC::~SolverMatchPatternC() {};


void SolverMatchPatternC::solve(Game* game)
{
	requiredLetters.clear();
	resetPattern();

	reducedWordList = wordList;
	wordListSizes.at(0) += reducedWordList.size();

	prevGuess = *std::min_element(reducedWordList.begin(), reducedWordList.end(), customSorterAsc);

	prevResult = game->guess(prevGuess);
	int guessNumber = 1;

	while (!game->isFinished() && !game->isWon())
	{
		for (int i = 0; i < 5; ++i)
		{
			if (prevResult[i] == '-')
			{
				removeFromPattern(prevGuess[i]);
			}
			else
			{
				if (prevResult[i] == '+')
				{
					if (!(std::find(requiredLetters.begin(), requiredLetters.end(), prevGuess[i]) != requiredLetters.end()))
						requiredLetters.push_back(prevGuess[i]);
					pattern[i].erase(std::remove(pattern[i].begin(), pattern[i].end(), prevGuess[i]), pattern[i].end());
				}
				else
				{
					pattern[i].clear();
					pattern[i].push_back(prevResult[i]);
				}

			}

		}

		reducedWordList = applyPattern();
		wordListSizes.at(guessNumber) += reducedWordList.size();

		prevGuess = *std::min_element(reducedWordList.begin(), reducedWordList.end(), customSorterAsc);

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

bool SolverMatchPatternC::customSorterAsc(std::string lhs, std::string rhs)
{
	const std::vector <char> leastCommonLetters{ 'q','x','j','z','v','w','f','k','g','b','h','p','m','y','c','d','u','n','t','l','i','r','o','s','e','a' };
	std::set<int> lhsScore;
	std::set<int> rhsScore;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 26; ++j)
		{
			if (lhs[i] == leastCommonLetters.at(j))
				lhsScore.insert(26 - j);
			if (rhs[i] == leastCommonLetters.at(j))
				rhsScore.insert(26 - j);
		}
	}
	int lhsSum = std::accumulate(lhsScore.begin(), lhsScore.end(), 0);
	int rhsSum = std::accumulate(rhsScore.begin(), rhsScore.end(), 0);
	return (lhsSum > rhsSum);
}


