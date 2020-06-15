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

int goal(greedy_solution_t sol);

#endif