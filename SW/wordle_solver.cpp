#include "wordle_solver.h"



void test(Solver* solver, std::ofstream& file, int timesToRun, std::vector <std::string> wordList, bool printToConsole)
{
	if (printToConsole)
	{
		std::cout << "running " << typeid(*solver).name() << std::endl;
	}

	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < timesToRun; i++)
	{
		Game game(wordList);
		solver->solve(&game);

		if (printToConsole)
			std::cout << i << "-";
	}

	if (printToConsole)
		std::cout << std::endl;

	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = end - start;

	file << typeid(*solver).name() << std::endl;
	file << "number of attempts: " << timesToRun << std::endl;
	file << "times won: " << solver->getTimesWon() << ", times lost: " << solver->getTimesLost() << std::endl;
	file << "job took " << time.count() << "seconds" << std::endl;
	std::vector<unsigned int> wordListSizes = solver->getWordListSizes();
	std::vector<int> wonAtGuess = solver->getWonAtGuess();

	for (int i = 0; i < 6; ++i)
		file << "mean Wordlist size after attempt " << i << ": " << ((float)wordListSizes.at(i) / (float)timesToRun) << std::endl;
	for (int i = 0; i < 7; ++i)
		file << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
	file << std::endl;

	delete solver;
}

void play(std::vector <std::string> wordList) //play in console
{
	std::string temp;
	Game game(wordList);
	while (!game.isFinished())
	{
		std::getline(std::cin, temp);
		std::cout << game.guess(temp) << std::endl;
	}

	if (game.isWon())
		std::cout << "You won!" << std::endl;
	else
		std::cout << "You lost!" << std::endl;

	std::cout << game.getSolution() << std::endl;
}

void reduceWordList(std::vector <std::string>& wordList, unsigned int finalSize)
{
	if (wordList.size() > finalSize && finalSize > 5)
		while (wordList.size() > finalSize)
		{
			std::swap(wordList[getRandomInt(0, wordList.size()-1)], wordList.back());
			wordList.pop_back();
		}
}



