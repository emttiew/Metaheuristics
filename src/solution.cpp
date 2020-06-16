#include "solution.h"
#include <algorithm>
#include <math.h>

void outint(int n) {
    std::cout << n << "\n";
}

int goal(greedy_solution_t & sol)
{   
    auto N = sol.problem->getNodes();
    auto edges = sol.problem->getEdges(); 
   
    for (int io = 0; io < edges.size() - 1; io++)
    {
        sol.nodes_to_color.push_back(io + 1);        
    }

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

edges_t graph_permutation(const greedy_solution_t & sol)
{
    auto N = sol.problem->getNodes();
    auto edges = sol.problem->getEdges(); 

    std::vector<int>::iterator it;    
    for(int i = 0; i < N; i++)
    {
       for(it = edges[i].begin(); it != edges[i].end(); it++) 
       {
        if (*it < N - 1)
            *it = fabs(*it + *(sol.nodes_to_color.begin()));
        else 
            *it = 0;        
       }
    }       
    return edges;
}

greedy_solution_t next_solution(const greedy_solution_t & sol)
{
    sol.problem->setEdges(graph_permutation(sol));
    greedy_solution_t next = sol;
    //std::next_permutation(sol.nodes_to_color.begin(), sol.nodes_to_color.end());
    return next;
}