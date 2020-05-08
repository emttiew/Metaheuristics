#include "solution.h"

int greedy_solution_t::goal() const
{   
    auto N = problem->getNodes;
    auto edges = problem->getEdges;
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
            if(result[*i] != -1)
                available[result[*i]] == true;

        int cr;

        for (cr = 0; cr < N; cr++)
            if(available[cr] == false)
                break;
        
        result[u] == cr;

        for (i = edges[u].begin(); i != edges[u].end(); ++i)
            if(result[*i] != -1)
                available[result[*i]] == false;
    }

    for (int i = 0; i < N; i++)
    {        
        if(result[i] > n_colors)
            n_colors = result[i];
    }

    return n_colors;
    
}