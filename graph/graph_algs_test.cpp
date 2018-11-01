#include "../catch.hpp"

#include "graph_algs.h"

TEST_CASE( "[IC] Null graph is connected", "[is_connected]" ) {
    Graph g;
    CHECK( is_connected(g) );
}

TEST_CASE( "[IC] Singleton graph is connected", "[is_connected]" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( is_connected(g) );
}

TEST_CASE( "[IC] Two vertices with edge", "[is_connected]" ) {
    Graph g;
    g.add_edge(0, 1);
    CHECK( is_connected(g) );
}

TEST_CASE( "[IC] Two vertices without edge", "[is_connected]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK_FALSE( is_connected(g) );
}

TEST_CASE( "[IC] Connected graph", "[is_connected]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(2, 4);
    CHECK( is_connected(g) );
}

TEST_CASE( "[IC] Disconnected graph", "[is_connected]" ) {
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

TEST_CASE( "[PE] Path in null graph doesn't exist", "[path_exists]" ) {
    Graph g;    
    CHECK_FALSE( path_exists(g, 0, 1) );
}

TEST_CASE( "[PE] Path in singleton graph exists", "[path_exists]" ) {
    Graph g;    
    g.add_vertex(0);
    CHECK( path_exists(g, 0, 0) );
}

TEST_CASE( "[PE] Path for two vertices without edge", "[path_exists]" ) {
    Graph g;    
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK_FALSE( path_exists(g, 0, 1) );
}

TEST_CASE( "[PE] Path for two vertices with edge", "[path_exists]" ) {
    Graph g;    
    g.add_edge(0, 1);
    CHECK( path_exists(g, 0, 1) );
}

TEST_CASE( "[PE] Path for several vertices", "[path_exists]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 3);
    CHECK( path_exists(g, 0, 3) );
    CHECK( path_exists(g, 1, 3) );
}

TEST_CASE( "[PE] Path in disconnected graph", "[path_exists]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(0, 3);
    g.add_edge(4, 5);
    g.add_edge(5, 6);
    g.add_vertex(7);
    CHECK( path_exists(g, 1, 3) );
    CHECK_FALSE( path_exists(g, 0, 5) );
    CHECK_FALSE( path_exists(g, 1, 7) );
    CHECK_FALSE( path_exists(g, 5, 7) );
}

TEST_CASE( "[PE] Reverse path", "[path_exists]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    CHECK( path_exists(g, 5, 0) );
    CHECK( path_exists(g, 4, 1) );
}

TEST_CASE( "[PE] Path with non-existing vertices", "[path_exists]" ) {
    Graph g;    
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.add_edge(3, 5);
    CHECK_FALSE( path_exists(g, 0, 7) );
    CHECK_FALSE( path_exists(g, 6, 2) );
    CHECK_FALSE( path_exists(g, 6, 8) );
}

