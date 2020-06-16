#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "graph.h"
#include <vector>
#include <iostream>

class greedy_solution_t {
public:
  std::shared_ptr<Graph> problem;
  std::vector<int> nodes_to_color;
};

int goal(greedy_solution_t & sol);

greedy_solution_t next_solution(const greedy_solution_t & sol);
edges_t graph_permutation(const greedy_solution_t & sol);

#endif