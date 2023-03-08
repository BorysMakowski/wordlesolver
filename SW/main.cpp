#include "wordle_solver.h"

int main()
{
	std::vector <std::string> wordList = propagateWordList();
	reduceWordList(wordList, 3000);
	std::ofstream results("results_100k_brutes.txt");
	int timesToRun = 100000;

	auto globalStart = std::chrono::system_clock::now();
	//std::ofstream results("results.txt", std::ios_base::app); //append instead of overwrite

	test(new BruteSolver(wordList), results, timesToRun, wordList, false);
	test(new BruteSolverNoRepeat(wordList), results, timesToRun, wordList, false);
	//test(new SolverA(wordList), results, timesToRun, wordList, false);
	//test(new SolverB(wordList), results, timesToRun, wordList, false);
	//test(new SolverC(wordList), results, timesToRun, wordList, false);
	//test(new SolverMatchPatternA(wordList), results, timesToRun, wordList, false);
	//test(new SolverMatchPatternB(wordList), results, timesToRun, wordList, false);
	//test(new SolverMatchPatternC(wordList), results, timesToRun, wordList, false);

	auto globalEnd = std::chrono::system_clock::now();
	std::chrono::duration<double> globalTime = globalEnd - globalStart;
	results << "whole job took: " << globalTime.count() << " seconds" << std::endl;
	results.close();

	//play(wordList);
	system("pause");
}

