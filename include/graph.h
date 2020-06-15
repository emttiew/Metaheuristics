#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector> 
#include <memory>

using edges_t = std::vector<std::vector<int>>; 
  
// A class that represents an undirected graph 
class Graph 
{ 
private:
    edges_t edges;
    int nodes; 
    edges_t edge_parser(edges_t graph);   
public:  
    Graph(int n = 0) : nodes(n) {};    
    int getNodes() const
    {
        return this->nodes;
    }
    edges_t getEdges() const
    {
        return this->edges;
    }
    void setEdges(const edges_t e) 
    {
        edges = e;  
    }
};
#endif