#pragma once
#include <string>
#include <chrono>

#include "game.h"
#include "tools.h"
#include "brute_solver.h"
#include "brute_solver_no_repeat.h"
#include "solver_a.h"
#include "solver_b.h"
#include "solver_c.h"
#include "solver_match_pattern_a.h"
#include "solver_match_pattern_b.h"
#include "solver_match_pattern_c.h"


void test(Solver* solver, std::ofstream& file, int timesToRun, std::vector <std::string> wordList, bool printToConsole = true);

//play in console
void play(std::vector <std::string> wordList);

void reduceWordList(std::vector <std::string>& wordList, unsigned int finalSize);




