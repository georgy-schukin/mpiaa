#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "../catch.hpp"

#include "count_sort.h"

bool are_equal(const std::vector<int> &a, const std::vector<int> &b) {
    return (a == b);
}

TEST_CASE( "Empty array", "[count_sort]" ) {    
    REQUIRE( are_equal(count_sort({}, 0, 0), {}) );
}

TEST_CASE( "One element array", "[count_sort]" ) {
    REQUIRE( are_equal(count_sort({1}, 1, 1), {1}) );
}

TEST_CASE( "Array from one element", "[count_sort]" ) { 
    REQUIRE( are_equal(count_sort({1, 1, 1, 1}, 1, 1), {1, 1, 1, 1}) );   
}

TEST_CASE( "Sorted array", "[count_sort]" ) {    
    REQUIRE( are_equal(count_sort({1, 2, 4, 9}, 1, 9), {1, 2, 4, 9}) );   
}

TEST_CASE( "Unsorted array", "[count_sort]" ) { 
    REQUIRE( are_equal(count_sort({3, 0, -1, 9, 2}, -1, 9), {-1, 0, 2, 3, 9}) );   
}

TEST_CASE( "Sorted array with duplicates", "[count_sort]" ) {
    REQUIRE( are_equal(count_sort({0, 1, 1, 2, 2, 2, 9}, 0, 10), {0, 1, 1, 2, 2, 2, 9}) );
}

TEST_CASE( "Unsorted array with duplicates", "[count_sort]" ) {
    REQUIRE( are_equal(count_sort({9, -1, 2, 1, -1, 3, 9, 2}, -10, 10), {-1, -1, 1, 2, 2, 3, 9, 9}) );
}

TEST_CASE( "Array with big range", "[count_sort]" ) {
    REQUIRE( are_equal(count_sort({1, 0, 100000, 0}, 0, 100000), {0, 0, 1, 100000}) );
}

