#include "game.h"


	Game::Game() 
	{
		tries = 0;
		wordList = propagateWordList();
		finished = false;
		result = false;
		solution = wordList.at(getRandomInt(0, wordList.size() - 1));
	}
	//constructor
	Game::Game(std::vector <std::string> _wordList)
	{
		wordList = _wordList;
		tries = 0;
		finished = false;
		result = false;
		solution = wordList.at(getRandomInt(0, wordList.size() - 1));
	};

	//copy constructor
	Game::Game(const Game& in)
	{
		wordList = in.wordList;
		solution = in.solution;
		tries = in.tries;
		finished = in.finished;
		result = in.result;
	}

	Game::~Game() {};

	std::string Game::guess(std::string _guess)
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
	std::string Game::getSolution()
	{
		return solution;
	};

	bool Game::isFinished()
	{
		return finished;
	}

	bool Game::isWon()
	{
		return result;
	}

	std::vector <std::string> Game::getWordList()
	{
		return wordList;
	}
	/*
	// HELPER FUNCTIONS
	*/
	bool Game::isLetterInSolution(char _in)
	{
		for (int i = 0; i < 5; i++)
			if (solution[i] == _in)
				return true;
		return false;
	}

	bool Game::isWordInWordList(std::string _in)
	{
		for (auto i : wordList)
			if (i == _in)
				return true;
		return false;
	}