#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "graph.h"

#include <algorithm>

template <class T, class U>
bool is_in(const T &container, const U &elem) {
    return (std::find(container.begin(), container.end(), elem) != container.end());
}

TEST_CASE( "Empty graph", "[graph]" ) {
    Graph g;
    CHECK_FALSE( g.has_vertex(0) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "One vertex", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( g.has_vertex(0) );
    CHECK_FALSE( g.has_vertex(1) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "Two vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "Edge", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_edge(0, 1) );
    CHECK( g.has_edge(1, 0) );
    CHECK_FALSE( g.has_edge(0, 0) );
}

TEST_CASE( "Loops are not allowed", "[graph]" ) {
    Graph g;
    g.add_edge(0, 0);
    g.add_edge(1, 1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK_FALSE( g.has_edge(0, 0) );
    CHECK_FALSE( g.has_edge(1, 1) );
}

TEST_CASE( "Two edges", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_vertex(3);
    g.add_edge(0, 3);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_vertex(3) );
    CHECK( g.has_edge(0, 1) );
    CHECK( g.has_edge(0, 3) );
    CHECK_FALSE( g.has_edge(1, 3) );
}

TEST_CASE( "Get vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_edge(0, 1);
    g.add_vertex(3);
    const auto vert = g.get_vertices();
    CHECK( vert.size() == 3);
    CHECK( is_in(vert, 0) );
    CHECK( is_in(vert, 1) );
    CHECK( is_in(vert, 3) );
}

TEST_CASE( "Get adjacent vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_vertex(3);
    const auto adj0 = g.get_adjacent_vertices(0);
    const auto adj1 = g.get_adjacent_vertices(1);
    const auto adj3 = g.get_adjacent_vertices(3);
    const auto adj4 = g.get_adjacent_vertices(4);
    CHECK( adj0.size() == 2);
    CHECK( is_in(adj0, 1) );
    CHECK( is_in(adj0, 2) );
    CHECK( adj1.size() == 1);
    CHECK( is_in(adj1, 0) );
    CHECK( adj3.size() == 0);
    CHECK( adj4.size() == 0);
}
