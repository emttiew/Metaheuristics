#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector> 
#include <memory>

using edges_t = std::vector<std::vector<int>>; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    std::shared_ptr<edges_t> edges;
    int nodes;    
public:  
    Graph(int n = 0);    
    int getNodes() const
    {
        return this->nodes;
    }
    std::shared_ptr<edges_t> getEdges() const
    {
        return this->edges;
    }
    void setEdges(const edges_t);
}; 

#endif