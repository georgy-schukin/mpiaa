#include "graph.h"

#include <vector>

/// Solve Travelling Salesman Problem (TSP) for the graph:
/// Find the shortest (with a minimal total weight) path and return it as an array of vertices.
std::vector<int> tsp(const Graph &graph, int start_vertex);