#include "../catch.hpp"

#include "graph.h"

#include <algorithm>
#include <set>

template <typename Container>
bool is_equal(const Container &c1, const Container &c2) {
    const auto s1 = std::set<typename Container::value_type>(c1.begin(), c1.end());
    const auto s2 = std::set<typename Container::value_type>(c2.begin(), c2.end());
    return s1 == s2;
}

TEST_CASE( "[Graph] Empty graph", "[graph]" ) {
    Graph g;
    CHECK_FALSE( g.has_vertex(0) );
    CHECK_FALSE( g.has_arc(0, 1) );
}

TEST_CASE( "[Graph] One vertex", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    CHECK( g.has_vertex(0) );
    CHECK_FALSE( g.has_vertex(1) );
    CHECK_FALSE( g.has_arc(0, 1) );
}

TEST_CASE( "[Graph] Two vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_vertex(1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK_FALSE( g.has_arc(0, 1) );
}

TEST_CASE( "[Graph] Arc", "[graph]" ) {
    Graph g;
    g.add_arc(0, 1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_arc(0, 1) );
    CHECK_FALSE( g.has_arc(1, 0) );
    CHECK_FALSE( g.has_arc(0, 0) );
}

TEST_CASE( "[Graph] Loop", "[graph]" ) {
    Graph g;
    g.add_arc(0, 0);
    g.add_arc(1, 1);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_arc(0, 0) );
    CHECK( g.has_arc(1, 1) );
}

TEST_CASE( "[Graph] Two arcs", "[graph]" ) {
    Graph g;
    g.add_arc(0, 1);
    g.add_arc(0, 3);
    CHECK( g.has_vertex(0) );
    CHECK( g.has_vertex(1) );
    CHECK( g.has_vertex(3) );
    CHECK( g.has_arc(0, 1) );
    CHECK( g.has_arc(0, 3) );
    CHECK_FALSE( g.has_arc(1, 0) );
    CHECK_FALSE( g.has_arc(3, 0) );
    CHECK_FALSE( g.has_arc(1, 3) );
}

TEST_CASE( "[Graph] Get vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_arc(0, 1);
    g.add_vertex(3);
    CHECK( is_equal(g.get_vertices(), {0, 1, 3} ));
}

TEST_CASE( "[Graph] Get adjacent vertices", "[graph]" ) {
    Graph g;
    g.add_vertex(0);
    g.add_arc(0, 1);
    g.add_arc(1, 2);
    g.add_arc(1, 3);
    g.add_arc(0, 2);
    g.add_vertex(3);
    g.add_arc(3, 1);
    CHECK( is_equal(g.get_adjacent_vertices(0), {1, 2} ));
    CHECK( is_equal(g.get_adjacent_vertices(1), {2, 3} ));
    CHECK( is_equal(g.get_adjacent_vertices(2), {} ));
    CHECK( is_equal(g.get_adjacent_vertices(3), {1} ));
    CHECK( is_equal(g.get_adjacent_vertices(4), {} ));
}
