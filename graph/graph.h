#pragma once

#include <map>
#include <set>
#include <vector>

class Graph {
public:
    Graph() {}
    ~Graph() {}

    /// Adds single vertex to the graph.
    void add_vertex(int vertex);

    /// Adds vertices (if necessary) and edge between them to the graph.
    /// If start and end vertices are the same, adds only one vertex (loops are not allowed).
    void add_edge(int start_vertex, int end_vertex);

    /// Returns all vertices of the graph.
    std::vector<int> get_vertices() const;

    /// Returns all vertices, adjacent to the specified.
    std::vector<int> get_adjacent_vertices(int src_vertex) const;

    /// Returns true if vertex exists in the graph, false otherwise.
    bool has_vertex(int vertex) const;

    /// Returns true if vertices exist and have edge between them, false otherwise.
    /// If start and end vertices are the same, returns false (loops are not allowed).
    bool has_edge(int start_vertex, int end_vertex) const;

private:
    std::map<int, std::set<int>> vertices;
};
