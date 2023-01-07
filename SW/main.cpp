
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

/*
TODO:
get rid of warnings
change vector + if to std::set
cleanup
*/

int main()
{

    std::vector <std::string> wordList = propagateWordList();
    std::ofstream results("results.txt");
    int timesToRun = 5;
    auto globalStart = std::chrono::system_clock::now();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER BRUTE FORCE
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BruteSolver bruteSolver;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        bruteSolver.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;

    results << "BRUTE SOLVER ATTEMPT:" << std::endl;
    results << "times won: " << bruteSolver.getTimesWon() << ", times lost: " << bruteSolver.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    std::vector<int> wordListSizes = bruteSolver.getWordListSizes();
    std::vector<int> wonAtGuess = bruteSolver.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER BRUTE FORCE NO REPEATS
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    BruteSolverNoRepeat bruteSolverNR;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        bruteSolverNR.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "BRUTE FORCE NO REPEATS ATTEMPT:" << std::endl;
    results << "times won: " << bruteSolverNR.getTimesWon() << ", times lost: " << bruteSolverNR.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = bruteSolverNR.getWordListSizes();
    wonAtGuess = bruteSolverNR.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER A
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverA solverA;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverA.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER A ATTEMPT:" << std::endl;
    results << "times won: " << solverA.getTimesWon() << ", times lost: " << solverA.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverA.getWordListSizes();
    wonAtGuess = solverA.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER B
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverB solverB;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverB.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER B ATTEMPT:" << std::endl;
    results << "times won: " << solverB.getTimesWon() << ", times lost: " << solverB.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverB.getWordListSizes();
    wonAtGuess = solverB.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER C
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverC solverC;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverC.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER C ATTEMPT:" << std::endl;
    results << "times won: " << solverC.getTimesWon() << ", times lost: " << solverC.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverC.getWordListSizes();
    wonAtGuess = solverC.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER MATCH PATTERN A
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverMatchPatternA solverMatchA;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverMatchA.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER MATCH PATTERN A ATTEMPT:" << std::endl;
    results << "times won: " << solverMatchA.getTimesWon() << ", times lost: " << solverMatchA.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverMatchA.getWordListSizes();
    wonAtGuess = solverMatchA.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER  MATCH PATTERN B
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverMatchPatternB solverMatchB;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverMatchB.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER MATCH PATTERN B ATTEMPT:" << std::endl;
    results << "times won: " << solverMatchB.getTimesWon() << ", times lost: " << solverMatchB.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverMatchB.getWordListSizes();
    wonAtGuess = solverMatchB.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //SOLVER  MATCH PATTERN C
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    SolverMatchPatternC solverMatchC;

    start = std::chrono::system_clock::now();
    for (int i = 0; i < timesToRun; i++)
    {
        Game game(wordList);
        solverMatchC.solve(&game);

        if (i % 1 == 0)
            std::cout << i << "-";
    }
    std::cout << std::endl;
    end = std::chrono::system_clock::now();
    time = end - start;

    results << "SOLVER MATCH PATTERN C ATTEMPT:" << std::endl;
    results << "times won: " << solverMatchC.getTimesWon() << ", times lost: " << solverMatchC.getTimesLost() << std::endl;
    results << "job took " << time.count() << "seconds" << std::endl;
    wordListSizes = solverMatchC.getWordListSizes();
    wonAtGuess = solverMatchC.getWonAtGuess();

    for (int i = 0; i < 7; ++i)
        results << "Wordlist size on attempt " << i << ": " << wordListSizes.at(i) << std::endl;

    for (int i = 0; i < 7; ++i)
        results << "Won at guess: " << i << ": " << wonAtGuess.at(i) << std::endl;
    results << std::endl;

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    auto globalEnd = std::chrono::system_clock::now();
    std::chrono::duration<double> globalTime = globalEnd - globalStart;
    results << "whole job took " << globalTime.count() << "seconds" << std::endl;


    /* play with console
    std::string temp;
    Game game(wordList);
    while (!game.isFinished())
    {
        std::getline(std::cin, temp);
        std::cout << game.guess(temp) << std::endl;
    }

    if (game.getResult() == true)
        std::cout << "You won!" << std::endl;
    else
        std::cout << "You lost!" << std::endl;
    */
    results.close();
}

