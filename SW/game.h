#pragma once
#include "tools.h"

class Game
{
public:
	Game();
	Game(std::vector <std::string> _wordList);

	//copy constructor
	Game(const Game& in);

	~Game();

	std::string guess(std::string _guess);

	/*
	// SETTERS, GETTERS
	*/
	std::string getSolution();

	bool isFinished();

	bool isWon();

	std::vector <std::string> getWordList();
	/*
	// HELPER FUNCTIONS
	*/
	bool isLetterInSolution(char _in);

	bool isWordInWordList(std::string _in);
private:
	std::string solution;
	int tries;
	std::vector <std::string> wordList;
	bool finished;
	bool result;

};