#include <iostream>
#include <string>
#include <chrono>

#include "game.h"
#include "tools.h"
#include "brute_solver.h"
#include "brute_solver_no_repeat.h"
#include "solver_a.h"
#include "solver_b.h"

std::string temp;

int main()
{

    std::vector <std::string> wordList = propagateWordList();

    //SolverA solver;

    //auto start = std::chrono::system_clock::now();
    //for (int i = 0; i < 1000; i++)
    //{
    //    Game game(wordList);
    //    solver.solve(&game);

    //    if (i % 100 == 0)
    //        std::cout << i << std::endl;
    //}
    //auto end = std::chrono::system_clock::now();
    //std::chrono::duration<double> time = end - start;

    //std::cout << "SOLVER A ATTEMPT:" << std::endl;
    //std::cout << "times won: " << solver.getTimesWon() << ", times lost: " << solver.getTimesLost() << std::endl;
    //std::cout << "job took " << time.count() << "seconds" << std::endl;

    //////////////////////////////////////////////////

    SolverB solverB;

    auto startB = std::chrono::system_clock::now();
    for (int i = 0; i < 100; i++)
    {
        Game game(wordList);
        solverB.solve(&game);

        if (i % 1 == 0)
            std::cout << i << std::endl;
    }
    auto endB = std::chrono::system_clock::now();
    std::chrono::duration<double> timeB = endB - startB;

    std::cout << "SOLVER B ATTEMPT:" << std::endl;
    std::cout << "times won: " << solverB.getTimesWon() << ", times lost: " << solverB.getTimesLost() << std::endl;
    std::cout << "job took " << timeB.count() << "seconds" << std::endl;

    /*
 //BRUTE FORCE
    std::vector <std::string> wordList = propagateWordList();

    BruteSolverNoRepeat solver;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < 10; i++)
    {
        Game game(wordList);
        solver.solve(&game);

        if (i % 50 == 0)
            std::cout << i << std::endl;
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> time = end - start;

    std::cout << "BRUTE FORCE ATTEMPT:" << std::endl;
    std::cout << "times won: " << solver.getTimesWon() << ", times lost: " << solver.getTimesLost() << std::endl;
    std::cout << "job took " << time.count() << "seconds" << std::endl;
    */

    /* play with console
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


    //game.guess("words");
    //game.guess("worse");
    //game.guess("arose");

}

