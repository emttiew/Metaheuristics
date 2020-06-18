#include "solution.h"
#include "solver_brute_force.h"
#include "json.hpp"
#include "solver_hill_climb_nd.h"
#include "solver_hill_climb.h"
#include "solver_tabu_search.h"
#include "solver_SA.h"
#include "solver_GA.h"
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
    std::random_device rd;
    std::mt19937 gen(rd());
    greedy_solution_t problem;
    inFile >> problem;
    {
    std::uniform_real_distribution<> dis(0.0, 1.0);
    auto get_random_neighbour = [&gen](auto e) {
      auto list0 = get_close_solutions(e);
      std::vector<greedy_solution_t> full_list;
      for (auto ne : list0) {
        auto n = get_close_solutions(ne);
        full_list.insert(full_list.end(), n.begin(), n.end());
      }
      for (int i = 0; i < 3; i++)
        full_list.insert(full_list.end(), list0.begin(), list0.end());
      std::uniform_int_distribution<> dis(0, full_list.size() - 1);
      return full_list.at(dis(gen));
    };
    auto u = [&dis, &gen](int n) { return dis(gen); };
    auto t_start = std::chrono::steady_clock::now();
    auto sol = simulated_annealing(
        [&]() { return randomize_solution(problem); }, get_random_neighbour,
        [](int n) { return 1.0 / n; }, goal, u, 2000);
    auto t_finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#simulated_annealing GOAL: " << goal(sol)
         << " dt: " << (elapsed_seconds).count() << "\n";
    results["simulated_annealing"] = {{"goal", std::to_string(goal(sol))}};
  }
    {
    auto t_start = std::chrono::steady_clock::now();
    auto sol = tabu_search([&]() { return randomize_solution(problem); },
                           get_close_solutions, goal, 2000, 50);
    auto t_finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#tabu_search GOAL: " << goal(sol)
         << " dt: " << (elapsed_seconds).count() << "\n";
    results["tabu_search"] = {{"goal", std::to_string(goal(sol))}};
    }
    {
    auto t_start = std::chrono::steady_clock::now();
    auto sol = hill_climbing([&]() { return randomize_solution(problem); },
                                get_close_solutions, goal, 2000);
    auto t_finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#hill_climbing GOAL: " << goal(sol)
         << " dt: " << (elapsed_seconds).count() << "\n";
    results["hill_climbing"] = {{"goal", std::to_string(goal(sol))}};
    }
    {
    auto t_start = std::chrono::steady_clock::now();
    auto sol = hill_climbing_nd([&]() { return randomize_solution(problem); },
                                get_close_solutions, goal, 2000);
    auto t_finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#hill_climbing_nd GOAL: " << goal(sol)
         << " dt: " << (elapsed_seconds).count() << "\n";
    results["hill_climbing_nd"] = {{"goal", std::to_string(goal(sol))}};
    }
    {
    auto t_start = std::chrono::steady_clock::now();
    auto sol =
        brute_force([problem]() { return problem; }, next_solution, goal);
    auto t_finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds = t_finish - t_start;
    std::cout << "#brute_force GOAL: " << goal(sol)
         << " dt: " << elapsed_seconds.count() << "\n";
    results["brute_force"] = {{"goal", std::to_string(goal(sol))}};
    }    
    inFile.close();    

    return 0;
}
