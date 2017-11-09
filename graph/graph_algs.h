#include "graph.h"

/// Returns true if graph is connected, false otherwise.
bool is_connected(const Graph &graph);

/// Returns true if there is a path from start vertex to end vertex, false otherwise.
bool path_exists(const Graph &graph, int start_vertex, int end_vertex);