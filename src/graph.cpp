#include "graph.h"

Graph::Graph(int n)
{
    nodes = n;
    edges = std::make_shared<edges_t>(n);
}

void Graph::setEdges(const edges_t e)
{
    *edges = e;    
}