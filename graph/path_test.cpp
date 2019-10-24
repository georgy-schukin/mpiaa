#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

#include "path.h"

TEST_CASE( "Path in an empty graph doesn't exist", "[path_exists]" ) {
    Graph g;    
    CHECK_FALSE( path_exists(g, 0, 1) );
}

TEST_CASE( "Path in singleton graph exists", "[path_exists]" ) {
    Graph g;    
    g.add_vertex(0);
    CHECK( path_exists(g, 0, 0) );
}

TEST_CASE( "Path in singleton graph with a loop exists", "[path_exists]" ) {
    Graph g;    
    g.add_vertex(0);
    g.add_arc(0, 0);
    CHECK( path_exists(g, 0, 0) );
}

TEST_CASE( "Path for two vertices without an arc", "[path_exists]" ) {
    Graph g;    
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK_FALSE( path_exists(g, 0, 1) );
}

TEST_CASE( "Path for two vertices with an arc", "[path_exists]" ) {
    Graph g;    
    g.add_arc(0, 1);
    CHECK( path_exists(g, 0, 1) );
    CHECK_FALSE( path_exists(g, 1, 0) );
}

TEST_CASE( "Path for several vertices", "[path_exists]" ) {
    Graph g;    
    g.add_arc(0, 1);
    g.add_arc(1, 2);
    g.add_arc(2, 3);
    g.add_arc(0, 3);
    CHECK( path_exists(g, 0, 3) );
    CHECK( path_exists(g, 1, 1) );
    CHECK( path_exists(g, 1, 3) );
    CHECK_FALSE( path_exists(g, 3, 0) );
    CHECK_FALSE( path_exists(g, 3, 1) );
}

TEST_CASE( "Path in a disconnected graph", "[path_exists]" ) {
    Graph g;    
    g.add_arc(0, 1);
    g.add_arc(1, 2);
    g.add_arc(2, 3);
    g.add_arc(0, 3);
    g.add_arc(4, 5);
    g.add_arc(5, 6);
    g.add_vertex(7);
    CHECK( path_exists(g, 1, 3) );
    CHECK_FALSE( path_exists(g, 0, 5) );
    CHECK_FALSE( path_exists(g, 1, 7) );
    CHECK_FALSE( path_exists(g, 5, 7) );
}

TEST_CASE( "Path with non-existing vertices", "[path_exists]" ) {
    Graph g;    
    g.add_arc(0, 1);
    g.add_arc(1, 2);
    g.add_arc(2, 3);
    g.add_arc(2, 4);
    g.add_arc(3, 5);
    CHECK_FALSE( path_exists(g, 0, 7) );
    CHECK_FALSE( path_exists(g, 6, 2) );
    CHECK_FALSE( path_exists(g, 6, 8) );
}

TEST_CASE( "Path in a graph with loops", "[path_exists]" ) {
    Graph g;    
    g.add_arc(0, 1);
    g.add_arc(1, 2);
    g.add_arc(2, 3);
    g.add_arc(3, 1);
    g.add_arc(3, 5);
    g.add_arc(5, 3);
    g.add_arc(5, 6);
    g.add_arc(6, 5);
    g.add_arc(0, 7);
    CHECK( path_exists(g, 0, 5) );
    CHECK( path_exists(g, 0, 6) );
    CHECK( path_exists(g, 1, 3) );
    CHECK( path_exists(g, 2, 1) );
    CHECK( path_exists(g, 6, 1) );
    CHECK( path_exists(g, 6, 2) );
    CHECK_FALSE( path_exists(g, 5, 0) );
    CHECK_FALSE( path_exists(g, 6, 7) );
}

