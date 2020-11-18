#include "../catch.hpp"

#include "min_spanning_tree.h"

#include <set>
#include <sstream>

using namespace std;

namespace {

using Edge = pair<int, int>;

Edge ordered(const Edge &e) {
    return (e.first <= e.second ? e : make_pair(e.second, e.first));
}

using EdgeSet = set<Edge>;

EdgeSet to_set(const std::vector<Edge> &edges) {
    EdgeSet result;
    for (const auto &e: edges) {
        result.insert(ordered(e));
    }
    return result;
}

}

namespace Catch {
    template<> 
    struct StringMaker<Edge> {
        static string convert(const Edge &e) {
            ostringstream out;
            out << "{" << e.first << ", " << e.second << "}";
            return out.str();
        } 
    };
}

TEST_CASE( "[MST] Empty graph", "[mst]") {
    Graph g {};    
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {} );
}

TEST_CASE( "[MST] Single vertex graph", "[mst]") {
    Graph g;
    g.add_vertex(0);   
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {} );
}

TEST_CASE( "[MST] One edge", "[mst]") {
    Graph g {{0, 1, 2.5}};
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {{0, 1}} );
}

TEST_CASE( "[MST] Two edges", "[mst]" ) {
    Graph g {{0, 1, 2.5}, {1, 2, 1.0}};
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {{0, 1}, {1, 2}} );
}

TEST_CASE( "[MST] Three edges", "[mst]" ) {
    Graph g {{0, 1, 2.5}, {1, 2, 1.0}, {0, 2, 0.7}};
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {{0, 2}, {1, 2}} );
}

TEST_CASE( "[MST] Many edges", "[mst]" ) {
    Graph g {{0, 1, 4.0}, {0, 7, 9.0}, 
             {1, 2, 8.0}, {1, 7, 11.0},
             {2, 3, 7.0}, {2, 5, 4.0}, {2, 8, 2.0},
             {3, 4, 9.0}, {3, 5, 14.0},
             {4, 5, 10.0},
             {5, 6, 2.0},
             {6, 7, 1.0}, {6, 8, 6.0},
             {7, 8, 7.0}};    
    CHECK( to_set(min_spanning_tree(g)) == EdgeSet {{0, 1}, {1, 2}, {2, 3}, {3, 4}, 
                                                    {2, 5}, {2, 8}, {5, 6}, {6, 7}} );
}

