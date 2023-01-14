#pragma once
#include "tools.h"

class Game
{
public:
	Game() {}
	//constructor
	Game(std::vector <std::string> _wordList)
	{
		wordList = _wordList;
		solution = "-----";
		tries = 0;
		finished = false;
		result = false;

		solution = wordList.at(getRandomInt(0, wordList.size() - 1));
	};

	//copy constructor
	Game(const Game& in)
	{
		wordList = in.wordList;
		solution = in.solution;
		tries = in.tries;
		finished = in.finished;
		result = in.result;
	}

	~Game() {};

	std::string guess(std::string _guess)
	{
		//verify imput
		if (!isWordInWordList(_guess))
		{
			std::cout << "not a word" << std::endl;
			return "-----";
		}

		//increment tries counter
		tries++;

		//prepare output
		std::string output = "";

		//game logic
		for (int i = 0; i < 5; i++)
		{
			if (_guess[i] == solution[i])
				output.push_back(solution[i]);
			else
			{
				if (isLetterInSolution(_guess[i]))
					output.push_back('+');
				else
					output.push_back('-');
			}
		}

		//check if guess is correct
		if (output == _guess)
		{
			finished = true;
			result = true;
			return output;
		}

		//check if current try was the last allowed
		if (tries < 6)
			return output;
		else
		{
			finished = true;
			result = false;
			return "-----";
		}
	};

	/*
	// SETTERS, GETTERS
	*/
	std::string getSolution()
	{
		return solution;
	};

	bool isFinished()
	{
		return finished;
	}

	bool isWon()
	{
		return result;
	}

	std::vector <std::string> getWordList()
	{
		return wordList;
	}
	/*
	// HELPER FUNCTIONS
	*/
	bool isLetterInSolution(char _in)
	{
		for (int i = 0; i < 6; i++)
			if (solution[i] == _in)
				return true;
		return false;
	}

	bool isWordInWordList(std::string _in)
	{
		for (auto i : wordList)
			if (i == _in)
				return true;
		return false;

	}
private:
	std::string solution = "-----";
	int tries = 0;
	std::vector <std::string> wordList;
	bool finished = false;
	bool result = false;

};