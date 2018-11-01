#include "catch.hpp"

#include "graph_algs_2.h"

#include <set>

namespace {
    template <class T>
    std::set<std::set<int>> to_set(const T &array) {
        std::set<std::set<int>> result;
        for (const auto &a: array) {
            result.insert(std::set<int>(std::begin(a), std::end(a)));
        }
        return result;
    }

    template <class T>
    bool sets_are_equal(const T &a1, const T &a2) {
        return (to_set(a1) == to_set(a2));
    }

    template <class T>
    bool equal(const T &a, const T &b) {
        return (a == b);
    }

    template <class T>
    bool one_from(const T &in, const typename std::vector<T> &variants) {
        for (const auto &v: variants) {
            if (in == v) return true;
        }
        return false;
    }
}

TEST_CASE( "[CC] Null graph has no components", "[connected_components]" ) {
    Graph g;
    CHECK( connected_components(g).empty() );
}

TEST_CASE( "[CC] Singleton graph has one component", "[connected_components]" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( sets_are_equal(connected_components(g), {{0}}) );
}

TEST_CASE( "[CC] Two vertices with edge", "[connected_components]" ) {
    Graph g;
    g.add_edge(0, 1);
    CHECK( sets_are_equal(connected_components(g), {{0, 1}}) );
}

TEST_CASE( "[CC] Two vertices without edge", "[connected_components]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( sets_are_equal(connected_components(g), {{0}, {1}}) );
}

TEST_CASE( "[CC] Connected graph", "[connected_components]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    CHECK( sets_are_equal(connected_components(g), {{0, 1, 2, 3, 4}}) );
}

TEST_CASE( "[CC] Disconnected graph", "[connected_components]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 6);
    CHECK( sets_are_equal(connected_components(g), {{0, 1, 2, 3}, {4, 5, 6}}) );
}

TEST_CASE( "[SP] Path in null graph doesn't exist", "[shortest_path]" ) {
    Graph g;    
    CHECK( shortest_path(g, 0, 1).empty() );
}

TEST_CASE( "[SP] Path in singleton graph exists", "[shortest_path]" ) {
    Graph g;    
    g.add_vertex(0);
    CHECK( equal(shortest_path(g, 0, 0), {0, 0}) );
}

TEST_CASE( "[SP] Path for two vertices without edge", "[shortest_path]" ) {
    Graph g;    
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( shortest_path(g, 0, 1).empty() );
}

TEST_CASE( "[SP] Path for two vertices with edge", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1);
    CHECK( equal(shortest_path(g, 0, 1), {0, 1}) );
}

TEST_CASE( "[SP] Path for several vertices", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 3);
    CHECK( equal(shortest_path(g, 0, 3), {0, 3}) );
    CHECK( one_from(shortest_path(g, 1, 3), {{1, 2, 3}, {1, 0, 3}}) );
}

TEST_CASE( "[SP] Path in disconnected graph", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 3);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_vertex(7);
    CHECK( equal(shortest_path(g, 0, 3), {0, 3}) );
    CHECK( one_from(shortest_path(g, 1, 3), {{1, 2, 3}, {1, 0, 3}}) );
    CHECK( shortest_path(g, 0, 5).empty() );
    CHECK( shortest_path(g, 1, 7).empty() );
    CHECK( shortest_path(g, 5, 7).empty() );
}

TEST_CASE( "[SP] Reverse path", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    CHECK( equal(shortest_path(g, 5, 0), {5, 3, 1, 0}) );
    CHECK( equal(shortest_path(g, 4, 1), {4, 2, 1}) );
}

TEST_CASE( "[SP] Path with non-existing vertices", "[shortest_path]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    CHECK( shortest_path(g, 0, 7).empty() );
    CHECK( shortest_path(g, 6, 2).empty() );
    CHECK( shortest_path(g, 6, 8).empty() );
}

