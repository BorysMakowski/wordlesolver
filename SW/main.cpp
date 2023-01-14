#include "wordle_solver.h"

int main()
{
	std::vector <std::string> wordList = propagateWordList();
	std::ofstream results("results.txt");
	int timesToRun = 100;

	auto globalStart = std::chrono::system_clock::now();
	//std::ofstream results("results.txt", std::ios_base::app); //append instead of overwrite

	test(new BruteSolver(wordList), results, timesToRun, wordList);
	test(new BruteSolverNoRepeat(wordList), results, timesToRun, wordList);
	test(new SolverA(wordList), results, timesToRun, wordList);
	test(new SolverB(wordList), results, timesToRun, wordList);
	test(new SolverC(wordList), results, timesToRun, wordList);
	test(new SolverMatchPatternA(wordList), results, timesToRun, wordList);
	test(new SolverMatchPatternB(wordList), results, timesToRun, wordList);
	test(new SolverMatchPatternC(wordList), results, timesToRun, wordList);

	auto globalEnd = std::chrono::system_clock::now();
	std::chrono::duration<double> globalTime = globalEnd - globalStart;
	results << "whole job took: " << globalTime.count() << "seconds" << std::endl;
	results.close();

	//play(wordList);
	system("pause");
}

