#include "solution.h"
#include "json.hpp"
#include <algorithm>
#include <math.h>
#include <random>

using nlohmann::json;

void outint(int n) {
    std::cout << n << "\n";
}

int goal(greedy_solution_t &sol)
{   
    auto N = sol.problem->getNodes();
    sol.problem->setAndParseEdges(sol.nodes_to_color);
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

void graph_permutation(greedy_solution_t &sol)
{
    auto N = sol.nodes_to_color.size();
    auto max = sol.problem->getNodes() - 1;
    std::vector<int>::iterator it;    
    for(int i = 0; i < N; i++)
    {
       for(it = sol.nodes_to_color[i].begin(); it != sol.nodes_to_color[i].end(); it++) 
       {
        if (*it < max)
            *it = *it + 1;
        else 
            *it = 0;        
       }
    }
}

greedy_solution_t & next_solution(greedy_solution_t &sol)
{
    std::next_permutation(sol.nodes_to_color.begin(), sol.nodes_to_color.end());
    graph_permutation(sol);
    return sol;
}

bool operator==(const greedy_solution_t &a, const greedy_solution_t &b)
{
    if(a.problem != b.problem)
        return false;
    if(a.nodes_to_color.size() != b.nodes_to_color.size())
        return false;
    for(unsigned i = 0; i < a.nodes_to_color.size(); i++)
    {
        if(a.nodes_to_color[i] != b.nodes_to_color[i])
            return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream &os, const greedy_solution_t &solution) 
{
  for(auto x : solution.problem->getEdges()) 
        {
            os << "\n";
            for (auto i : x)
                os << i << "\t";
        }
  return os;
}

std::istream &operator>>(std::istream &os, greedy_solution_t &problem) {
  json data;
  int i = 0;
  os >> data;
  problem.nodes_to_color.clear();
  for (auto e : data.at("problem")) {
    problem.nodes_to_color.push_back(
        {e.at("x"), e.at("y")});    
  }
  Graph graph(problem.nodes_to_color);
  problem.problem = std::make_shared<Graph>(graph);
  return os;
}

std::vector<greedy_solution_t> get_close_solutions(const greedy_solution_t sol0) {
  auto sol = sol0;
  std::vector<greedy_solution_t> ret;
  for (unsigned i = 0; i < sol.nodes_to_color.size(); i++) {
    ret.push_back(sol);
  }

  // zamieniamy miejscami 2 ze sobą
  for (int i = 0; i < (int)sol.nodes_to_color.size(); i++) {
    std::swap(ret.at(i).nodes_to_color.at(i),
              ret.at(i).nodes_to_color.at((i + 1) % sol.nodes_to_color.size()));
  }
  return ret;
}

greedy_solution_t randomize_solution(greedy_solution_t &initial_problem) 
{
  static std::random_device rd;
  static std::mt19937 gen(rd());
  graph_permutation(initial_problem);
  edges_t graph = initial_problem.nodes_to_color; 
  initial_problem.nodes_to_color.clear(); 
  std::random_shuffle(graph.begin(), graph.end(),
                      [](int i) { return gen() % i; });
  initial_problem.nodes_to_color = graph;
  initial_problem.problem->setAndParseEdges(graph);
  return initial_problem;
};