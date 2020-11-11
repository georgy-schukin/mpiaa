#include "../catch.hpp"

#include "shortest_path.h"

using namespace std;

TEST_CASE( "[Path] Empty graph", "[path]" ) {
    Graph g {};    
    CHECK( shortest_path(g, 0, 1) == vector<int> {} );
}

TEST_CASE( "[Path] Single vertex path", "[path]" ) {
    Graph g {{0, 1, 2.5}, {0, 2, 3.0}};    
    CHECK( shortest_path(g, 0, 0) == vector<int> {} );
}

TEST_CASE( "[Path] One edge", "[path]" ) {
    Graph g {{0, 1, 2.5}};
    CHECK( shortest_path(g, 0, 1) == vector<int> {0, 1} );
}

TEST_CASE( "[Path] Two edges", "[path]" ) {
    Graph g {{0, 1, 2.5}, {0, 2, 1.0}};
    CHECK( shortest_path(g, 0, 1) == vector<int> {0, 1} );
}

TEST_CASE( "[Path] Three edges", "[path]" ) {
    Graph g {{0, 1, 2.5}, {0, 2, 1.0}, {2, 1, 0.7}};
    CHECK( shortest_path(g, 0, 1) == vector<int> {0, 2, 1} );
}

TEST_CASE( "[Path] Many edges", "[path]" ) {
    Graph g {{0, 1, 3.0}, {1, 2, 0.5}, {2, 3, 0.5}, {3, 4, 1.0},
             {0, 2, 2.0}, {0, 4, 5.0}, {1, 3, 2.0}, {2, 4, 2.0}};
    CHECK( shortest_path(g, 0, 4) == vector<int> {0, 2, 3, 4} );
    CHECK( shortest_path(g, 4, 0) == vector<int> {4, 3, 2, 0} );
    CHECK( shortest_path(g, 1, 4) == vector<int> {1, 2, 3, 4} );    
}

TEST_CASE( "[Path] Unreachable vertex", "[path]" ) {
    Graph g {{0, 1, 2.5}, {1, 2, 1.0}, {0, 2, 1.0}, {3, 4, 0.7}};
    CHECK( shortest_path(g, 0, 4) == vector<int> {} );
    CHECK( shortest_path(g, 3, 0) == vector<int> {} );
}


