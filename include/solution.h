#include "graph.h"
#include <vector>
#include <iostream>

using problem_t = std::vector<Graph>;

class solution_t {
public:
  virtual double goal() const = 0;
};

class greedy_solution_t : public solution_t {
public:
  std::shared_ptr<problem_t> problem;  
  double goal() const;
};