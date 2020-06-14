#include "solution.h"
#include <algorithm>

void outint(int n) {
    std::cout << n << "\n";
}

int greedy_solution_t::goal() const
{   
    //auto N = problem->getNodes;
   // auto edges = problem->getEdges;

    
    edges_t edges1  = {
        {0, 1},
        {0, 2},
        {1, 2},
        {1, 3},
        {2, 3},
        {3, 4}
    };

    edges_t edges  = {
        {1, 2},
        {0, 2, 3},
        {0, 1, 3},
        {1, 2, 4},
        {3}
    };
    const int N = 5;

    int result[N];
    int n_colors = 0;
    result[0] = 0;

    for (int u = 1; u < N; u++)
        result[u] = -1;
    
    bool available[N];
    for (int cr = 0; cr < N; cr++) 
        available[cr] = false;

    for (int u = 1; u < N; u++)
    {
        std::vector<int>::iterator i;
        for (i = edges[u].begin(); i != edges[u].end(); ++i)
            if(result[*i] != -1) {
                available[result[*i]] = true;
            }

        int cr;

        for (cr = 0; cr < N; cr++)
            if(available[cr] == false)                
                break;       
        
        result[u] = cr;

        for (i = edges[u].begin(); i != edges[u].end(); ++i)
            if(result[*i] != -1)
                available[result[*i]] = false;
    }
    
    n_colors = *std::max_element(result, result + N) + 1;

    return n_colors;    
}