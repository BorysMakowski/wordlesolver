#pragma once
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <map>

std::vector <std::string> propagateWordList()
{
	std::vector <std::string> wordList;
	std::string temp;
	std::ifstream wordFile("words_alpha.txt");
	if (wordFile.is_open())
	{
		while (getline(wordFile, temp))
		{
			if (temp.length() == 5)
				wordList.push_back(temp);
		}
		wordFile.close();
	}
	//std::cout << wordList.size() << std::endl;
	return wordList;
}

int getRandomInt(int lowest, int highest)
{
	std::random_device randomDevice;
	std::mt19937 generator(randomDevice());
	std::uniform_int_distribution<> distribution(lowest, highest);
	return distribution(generator);
}

void getLetterOccurences()
{
	std::map <char, int> letters;
	std::vector <std::string> wordList = propagateWordList();
	for (auto i : wordList)
	{
		for (auto j : i)
			letters[j]++;
	}
	std::vector <std::pair<int, char>> lettersSorted;
	for (auto i : letters)
		lettersSorted.push_back(std::make_pair(i.second, i.first));

	std::sort(lettersSorted.rbegin(), lettersSorted.rend());
	for (auto i : lettersSorted)
		std::cout << i.first << ", " << i.second << std::endl;	
}