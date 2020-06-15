#include "solution.h"
#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    edges_t graph_edges = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 3},
        {3, 4}
    };

    // edges_t edges  = {
    //     {1, 2},
    //     {0, 2, 3},
    //     {0, 1, 3},
    //     {1, 2, 4},
    //     {3}
    // };

    Graph graph(graph_edges);
    std::cout << graph.getNodes() << "\n";
    for(auto x : graph.getEdges()) 
    {
        std::cout << "\n";
        for (auto i : x)
            std::cout << i << "\t";
    }
    std::cout << "\n";
    greedy_solution_t sol;
    sol.problem = std::make_shared<Graph>(graph);
    std::cout << "color used: " << goal(sol) << std::endl;

    // do {
    //     sol.problem->setEdges(graph_edges);
    //     std::cout << "color used: " << goal(sol) << std::endl;
    // } while(std::next_permutation(graph_edges.begin(), graph_edges.end()));
    return 0;
}
