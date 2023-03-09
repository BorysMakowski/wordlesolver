#include "wordle_solver.h"

int main()
{
	std::vector <std::string> wordList = propagateWordList();
	reduceWordList(wordList, 3000);
	std::ofstream results("results.txt");
	int timesToRun = 100;

	test(new BruteSolver(wordList), results, timesToRun, wordList, false);
	test(new BruteSolverNoRepeat(wordList), results, timesToRun, wordList, false);
	test(new SolverA(wordList), results, timesToRun, wordList, false);
	test(new SolverB(wordList), results, timesToRun, wordList, false);
	test(new SolverC(wordList), results, timesToRun, wordList, false);
	test(new SolverMatchPatternA(wordList), results, timesToRun, wordList, false);
	test(new SolverMatchPatternB(wordList), results, timesToRun, wordList, false);
	test(new SolverMatchPatternC(wordList), results, timesToRun, wordList, false);

	results.close();
}
