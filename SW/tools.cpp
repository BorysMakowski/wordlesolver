#include "tools.h"

std::vector <std::string> propagateWordList(std::string file_path)
{
	std::vector <std::string> wordList;
	std::string temp;
	std::ifstream wordFile(file_path);
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
