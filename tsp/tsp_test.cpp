#include "../catch.hpp"

#include "tsp.h"

using namespace std;

// For a circilar path get its reverse.
vector<int> reversed(const vector<int> &path) {
    if (path.empty()) {
        return vector<int> {};
    }
    vector<int> result = {path[0]}; // first item is a start vertex
    result.insert(result.end(), path.rbegin(), path.rend()); // add vertices in reverse order
    result.pop_back(); // remove duplicated start vertex
    return result;
}

// From two possible directions for a circlular path choose one with min second vertex.
vector<int> min_dir(const vector<int> &path) {
    if (path.size() <= 1) {
        return path;
    }    
    const auto reversed_path = reversed(path);
    return (path[1] <= reversed_path[1] ? path : reversed_path);
}

TEST_CASE( "[TSP] Empty graph", "[tsp]" ) {
    Graph g {};    
    CHECK( tsp(g, 0) == vector<int> {} );
}

TEST_CASE( "[TSP] Single vertex", "[tsp]" ) {
    Graph g {}; 
    g.add_vertex(0);   
    CHECK( tsp(g, 0) == vector<int> {} );
}

TEST_CASE( "[TSP] One edge", "[tsp]" ) {
    Graph g {{0, 1, 2.5}};
    CHECK( tsp(g, 0) == vector<int> {0, 1} );
}

TEST_CASE( "[TSP] Three vertices, three edges", "[tsp]" ) {
    Graph g {{0, 1, 2.5}, {0, 2, 0.5}, {1, 2, 1.0}};
    const auto result = tsp(g, 0);  
    const auto expected = vector<int> {0, 1, 2};  
    CHECK( min_dir(result) == expected );
}

TEST_CASE( "[TSP] Several vertices", "[tsp]" ) {
    Graph g {{0, 1, 6.0}, {0, 2, 4.0}, {0, 3, 1.0},
             {1, 2, 3.5}, {1, 3, 2.0}, 
             {2, 3, 5.0}};
    const auto result = tsp(g, 0);
    const auto expected = vector<int> {0, 2, 1, 3};
    CHECK( min_dir(result) == expected );
}

TEST_CASE( "[TSP] Many vertices", "[tsp]" ) {
    Graph g {{0, 1, 2.0}, {0, 2, 4.0}, {0, 3, 1.0}, {0, 4, 2.5},
             {1, 2, 3.6}, {1, 3, 6.0}, {1, 4, 3.0}, 
             {2, 3, 7.0}, {2, 4, 5.0}, 
             {3, 4, 9.0}};            
    const auto result = tsp(g, 0);
    const auto expected = vector<int> {0, 3, 2, 1, 4};
    CHECK( min_dir(result) == expected );
}

TEST_CASE( "[TSP] Unreachable vertex", "[tsp]" ) {
    Graph g {{0, 1, 2.5}, {1, 2, 1.0}, {0, 2, 1.0}, {3, 4, 0.7}};
    CHECK( tsp(g, 0) == vector<int> {} );
    CHECK( tsp(g, 3) == vector<int> {} );
}

TEST_CASE( "[TSP] No looped path", "[tsp]" ) {
    Graph g {{0, 1, 2.5}, {0, 2, 1.0}, {2, 3, 7.0} };
    CHECK( tsp(g, 0) == vector<int> {} );
    CHECK( tsp(g, 1) == vector<int> {} );
}


