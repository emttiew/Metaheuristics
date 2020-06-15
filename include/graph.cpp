#include "graph.h"
#include <algorithm>

edges_t Graph::edge_parser(edges_t graph)
{
    edges_t temp;
    for (auto x : graph)
    {
        temp.at(x[0]).push_back(x[1]);
        temp.at(x[1]).push_back(x[0]);
    }
    return temp;
}