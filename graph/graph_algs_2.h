#include "graph.h"

#include <vector>

/// Returns connected components of the graph as array of arrays of vertices.
std::vector<std::vector<int>> connected_components(const Graph &graph);

/// Returns shortest path from start to end vertex as array of vertices.
std::vector<int> shortest_path(const Graph &graph, int start_vertex, int end_vertex);
