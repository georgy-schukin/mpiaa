#pragma once

#include <map>
#include <set>
#include <vector>

class Graph {
public:
    Graph() {}
    ~Graph() {}

    void add_vertex(int vertex);
    void add_edge(int start_vertex, int end_vertex);

    std::vector<int> get_vertices() const;
    std::vector<int> get_adjacent_vertices(int src_vertex) const;

    bool has_vertex(int vertex) const;
    bool has_edge(int start_vertex, int end_vertex) const;

private:
    std::map<int, std::set<int>> vertices;
};
