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
    edges_t edge_parser(const edges_t & graph);   
public:  
    Graph(edges_t graph) : nodes(edge_parser(graph).size()), edges(edge_parser(graph)) {};    
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
        edges = edge_parser(e);  
    }
};
#endif