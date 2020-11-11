#include "../catch.hpp"

#include "graph.h"

#include <algorithm>
#include <set>
#include <sstream>

using namespace std;

template <typename Container>
set<typename Container::value_type> to_set(const Container &c) {
    return set<typename Container::value_type>(c.begin(), c.end());
}

template <typename Container>
Container sorted(const Container &c) {
    Container copy = c;
    sort(begin(copy), end(copy));
    return copy;
}

namespace Catch {
    template<> 
    struct StringMaker<pair<int, double>> {
        static string convert(const pair<int, double> &p) {
            ostringstream out;
            out << "{" << p.first << ", " << p.second << "}";
            return out.str();
        } 
    };
}

TEST_CASE( "[Graph] Empty graph", "[graph]" ) {
    Graph g;
    CHECK_FALSE( g.has_vertex(0) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "[Graph] One vertex", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( g.has_vertex(0) );
    CHECK_FALSE( g.has_vertex(1) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "[Graph] Two vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK_FALSE( g.has_edge(0, 1) );
}

TEST_CASE( "[Graph] One edge", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1, 5.0);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_edge(0, 1) );
    CHECK( g.has_edge(1, 0) );
    CHECK( g.edge_weight(0, 1) == 5.0 );
    CHECK_FALSE( g.has_edge(0, 0) );
}

TEST_CASE( "[Graph] Loop", "[graph]" ) {
    Graph g;
    g.add_edge(0, 0);
    g.add_edge(1, 1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_edge(0, 0) );
    CHECK( g.has_edge(1, 1) );
}

TEST_CASE( "[Graph] Two edges", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 3);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_vertex(3) );
    CHECK( g.has_edge(0, 1) );
    CHECK( g.has_edge(0, 3) );
    CHECK( g.has_edge(1, 0) );
    CHECK( g.has_edge(3, 0) );
    CHECK_FALSE( g.has_edge(1, 3) );
}

TEST_CASE( "[Graph] Get vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_edge(0, 1);
    g.add_vertex(3);
    CHECK( sorted(g.get_vertices()) == vector<int> {0, 1, 3} );
}

TEST_CASE( "[Graph] Get adjacent vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_edge(0, 1);
    g.add_edge(0, 2, 4.5);    
    g.add_edge(1, 2, 3.0);
    g.add_edge(1, 3);        
    CHECK( sorted(g.get_adjacent_vertices(0)) == vector<int> {1, 2} );
    CHECK( sorted(g.get_adjacent_vertices(1)) == vector<int> {0, 2, 3} );
    CHECK( sorted(g.get_adjacent_vertices(2)) == vector<int> {0, 1} );
    CHECK( sorted(g.get_adjacent_vertices(3)) == vector<int> {1} );
    CHECK( sorted(g.get_adjacent_vertices(4)) == vector<int> {} );
    CHECK( g.edge_weight(1, 2) == 3.0 );
    CHECK( g.edge_weight(2, 0) == 4.5 );
    CHECK_THROWS( g.edge_weight(0, 3) );
}

TEST_CASE( "[Graph] Get adjacent edges", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2, 4.5);
    g.add_edge(1, 2, 3.0);    
    g.add_edge(3, 1, 7.2);
    using ESet = set<pair<int, double>>;
    CHECK( to_set(g.get_adjacent_edges(0)) == ESet {make_pair(1, 1.0), make_pair(2, 4.5)} );
    CHECK( to_set(g.get_adjacent_edges(1)) == ESet {make_pair(0, 1.0), make_pair(2, 3.0), make_pair(3, 7.2)} );
    CHECK( to_set(g.get_adjacent_edges(2)) == ESet {make_pair(0, 4.5), make_pair(1, 3.0)} );
    CHECK( to_set(g.get_adjacent_edges(3)) == ESet {make_pair(1, 7.2)} );
    CHECK( to_set(g.get_adjacent_edges(4)) == ESet {} );    
}

TEST_CASE( "[Graph] Replace an edge", "[graph]" ) {
    Graph g;
    g.add_edge(1, 5, 3.5);
    g.add_edge(5, 1, 4.7);
    CHECK( g.has_edge(1, 5) );
    CHECK( g.has_edge(5, 1) );
    CHECK( g.edge_weight(1, 5) == 4.7 );
    CHECK( g.edge_weight(5, 1) == 4.7 );
}

TEST_CASE( "[Graph] Remove vertices and edges", "[graph]" ) {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(2, 3);
    g.add_edge(2, 4);
    g.remove_vertex(2);    
    CHECK_FALSE( g.has_vertex(2) );
    CHECK_FALSE( g.has_edge(1, 2) );
    CHECK_FALSE( g.has_edge(3, 2) );
    CHECK_FALSE( g.has_edge(4, 2) );    
    CHECK( g.has_edge(0, 1) );    
    CHECK( g.has_edge(0, 4) );
    CHECK( g.has_edge(1, 3) );    
    g.remove_edge(0, 1);
    CHECK_FALSE( g.has_edge(0, 1) );    
    CHECK( g.has_vertex(0) );    
    CHECK( g.has_vertex(1) );    
}

