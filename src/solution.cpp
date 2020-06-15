#include "solution.h"
#include <algorithm>

void outint(int n) {
    std::cout << n << "\n";
}

int goal(greedy_solution_t sol)
{   
    auto N = sol.problem->getNodes();
    auto edges = sol.problem->getEdges(); 

    std::vector<int> result(N);
    int n_colors = 0;
    result[0] = 0;

    for (int u = 1; u < N; u++)
        result[u] = -1;
    
    std::vector<bool> available(N);
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
    
    n_colors = *std::max_element(result.begin(), result.end()) + 1;
    return n_colors;    
}