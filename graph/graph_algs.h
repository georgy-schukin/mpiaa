#include "graph.h"

/// Returns true if graph is connected, false otherwise.
bool is_connected(const Graph &g);

/// Returns true if there is a path from start vertex to end vertex, false otherwise.
bool path_exists(const Graph &g, int start_vertex, int end_vertex);