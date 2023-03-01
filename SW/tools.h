#pragma once
#include <string>
#include <fstream>
#include <random>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <numeric>

std::vector <std::string> propagateWordList(std::string file_path = "words_alpha.txt");

int getRandomInt(int lowest, int highest);
