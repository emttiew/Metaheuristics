#include "solution.h"
#include "solver_brute_force.h"
#include "json.hpp"
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <chrono>
#include <random>
#include <fstream>

int main(int argc,char* argv[])
{
    std::ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile) {
        std::cout << "Unable to open file\n";
        exit(1); // terminate with error
    }
    std::map<std::string, std::map<std::string, std::string>> results;
    greedy_solution_t problem;
    inFile >> problem;
    std::cout << problem << "\n---------------------\n";
    auto t_start = std::chrono::steady_clock::now();
    auto sol =
        brute_force([problem]() { return problem; }, next_solution, goal);
    auto t_finish = std::chrono::steady_clock::now();
     std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#brute_force GOAL: " << goal(sol)
         << " dt: " << elapsed_seconds.count() << "\n";
    results["brute_force"] = {{"goal", std::to_string(goal(sol))}};
    inFile.close();    

    return 0;
}
