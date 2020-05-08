#ifndef SOLUTION_H_
#define SOLUTION_H_

#include "graph.h"
#include <vector>
#include <iostream>

class solution_t {
public:
  virtual int goal() const = 0;
};

class greedy_solution_t : public solution_t {  
public:
  std::shared_ptr<Graph> problem;  
  int goal() const;
};

#endif