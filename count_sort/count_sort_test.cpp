#include "../catch.hpp"

#include "count_sort.h"

TEST_CASE( "Empty array", "[count_sort]" ) {    
    CHECK( count_sort({}, 0, 0) == std::vector<int> {} );
}

TEST_CASE( "One element array", "[count_sort]" ) {
    CHECK( count_sort({1}, 1, 1) == std::vector<int> {1} );
}

TEST_CASE( "Array from one element", "[count_sort]" ) { 
    CHECK( count_sort({1, 1, 1, 1}, 1, 1) == std::vector<int> {1, 1, 1, 1} );   
}

TEST_CASE( "Sorted array", "[count_sort]" ) {    
    CHECK( count_sort({1, 2, 4, 9}, 1, 9) == std::vector<int> {1, 2, 4, 9} );   
}

TEST_CASE( "Unsorted array", "[count_sort]" ) { 
    CHECK( count_sort({3, 0, -1, 9, 2}, -1, 9) == std::vector<int> {-1, 0, 2, 3, 9} );   
}

TEST_CASE( "Sorted array with duplicates", "[count_sort]" ) {
    CHECK( count_sort({0, 1, 1, 2, 2, 2, 9}, 0, 10) == std::vector<int> {0, 1, 1, 2, 2, 2, 9} );
}

TEST_CASE( "Unsorted array with duplicates", "[count_sort]" ) {
    CHECK( count_sort({9, -1, 2, 1, -1, 3, 9, 2}, -10, 10) == std::vector<int> {-1, -1, 1, 2, 2, 3, 9, 9} );
}

TEST_CASE( "Array with big range", "[count_sort]" ) {
    CHECK( count_sort({1, 0, 1000000, 0, -1000000}, -2000000, 2000000) == std::vector<int> {-1000000, 0, 0, 1, 1000000} );
}

