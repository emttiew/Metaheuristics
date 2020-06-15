#include "solution.h"
#include <vector>
#include <iostream>

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

    Graph graph(graph_edges);
    std::cout << graph.getNodes() << "\n";
    for(auto x : graph.getEdges()) 
    {
        std::cout << "\n";
        for (auto i : x)
            std::cout << i << "\t";
    }
    // greedy_solution_t sol;
    // sol.problem = std::make_shared<Graph>(graph);
    
    // std::cout << sol.goal() << std::endl;
    return 0;
}
