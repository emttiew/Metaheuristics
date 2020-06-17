#include "solution.h"
#include "solver_brute_force.h"
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <chrono>
#include <random>

int main()
{
    edges_t graph_edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 4},
        {2, 4},
        {4, 3}
    };

    // edges_t graph_edges = {
    //     {0, 1},
    //     {0, 2},
    //     {1, 2},
    //     {1, 3},
    //     {2, 3},
    //     {3, 4}
    // };

    // edges_t edges  = {
    //     {1, 2},
    //     {0, 2, 3},
    //     {0, 1, 3},
    //     {1, 2, 4},
    //     {3}
    // };

    //     edges_t edges  = {
    //     {1, 2},
    //     {0, 2, 4},
    //     {0, 1, 4},
    //     {4},
    //     {1, 2, 3}
    // };

    std::map<std::string, std::map<std::string, std::string>> results;
    Graph graph(graph_edges);
    // greedy_solution_t sol;
    greedy_solution_t problem;
    problem.problem = std::make_shared<Graph>(graph);
    problem.nodes_to_color = graph_edges;
    // sol.problem = std::make_shared<Graph>(graph);
    // sol.nodes_to_color = graph_edges;
    // std::cout << sol << "\n";
    // int k = 4;
    // do {        
    //     std::cout << next_solution(sol) << "\n";
    //     std::cout << "color used: " << goal(sol) << std::endl;
    //     k--;
    // } while (k > 0);    

    auto t_start = std::chrono::steady_clock::now();
    auto sol =
        brute_force([problem]() { return problem; }, next_solution, goal);
    auto t_finish = std::chrono::steady_clock::now();
    std::cout << "#brute_force GOAL: " << goal(sol)
         << " dt: " << (t_finish - t_start).count() << "\n";
    results["brute_force"] = {{"goal", std::to_string(goal(sol))}};
    

    return 0;
}
