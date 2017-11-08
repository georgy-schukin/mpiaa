#include "catch.hpp"

#include "graph_algs.h"

TEST_CASE( "Null graph is connected" ) {
    Graph g;
    CHECK( is_connected(g) );
}

TEST_CASE( "Singleton graph is connected" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( is_connected(g) );
}

TEST_CASE( "Two vertices with edge" ) {
    Graph g;
    g.add_edge(0, 1);
    CHECK( is_connected(g) );
}

TEST_CASE( "Two vertices without edge" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK_FALSE( is_connected(g) );
}

TEST_CASE( "Connected graph" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    CHECK( is_connected(g) );
}

TEST_CASE( "Disconnected graph" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(4, 5);
    g.add_edge(4, 6);
    g.add_edge(5, 6);
    CHECK_FALSE( is_connected(g) );
}

