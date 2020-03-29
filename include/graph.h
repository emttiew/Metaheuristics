#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector> 

using std::vector; 
  
// A class that represents an undirected graph 
class Graph 
{ 
    vector<vector<unsigned int>> graph;
    unsigned int n_nodes, n_edges;
    unsigned int used_colors;
public: 
    unsigned int getUsedColors(){
        return this->used_colors;
    }
    unsigned int getNodes(){
        return this->n_nodes;
    }
    unsigned int getEdges(){
        return this->n_edges;
    }
    vector<vector<unsigned int>> getGraph(){
        return this->graph;
    }
}; 

#endif