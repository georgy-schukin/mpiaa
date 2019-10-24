#include "graph.h"

void Graph::add_vertex(int vertex) {
    if (!has_vertex(vertex)) {
        vertices[vertex] = std::set<int>();
    }
}

void Graph::add_arc(int start_vertex, int end_vertex) {
    add_vertex(start_vertex);
    add_vertex(end_vertex);
    vertices[start_vertex].insert(end_vertex);
}

std::vector<int> Graph::get_vertices() const {
    std::vector<int> result;
    for (const auto &p: vertices) {
        result.push_back(p.first);
    }
    return result;
}

std::vector<int> Graph::get_adjacent_vertices(int src_vertex) const {
    const auto it = vertices.find(src_vertex);
    if (it == vertices.end()) {
        return std::vector<int>();
    }
    return std::vector<int>(it->second.begin(), it->second.end());
}

bool Graph::has_vertex(int vertex) const {
    return (vertices.find(vertex) != vertices.end());
}

bool Graph::has_arc(int start_vertex, int end_vertex) const {
    if (!has_vertex(start_vertex) || !has_vertex(end_vertex)) {
        return false;
    }
    const auto it = vertices.find(start_vertex);
    return (it->second.find(end_vertex) != it->second.end());
}
