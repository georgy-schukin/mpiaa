#include "../catch.hpp"

#include "sort.h"

using namespace std;

vector<int> sorted(const vector<int> &data) {
    auto data_sorted = data; // copy input
    sort(data_sorted); // sort array
    return data_sorted; // return sorted array
}

void check(const vector<int> &input, const vector<int> &expected) {
    const auto output = sorted(input);
    REQUIRE( output == expected );
}

TEST_CASE( "Empty array" ) {    
    check( {}, {} );
}

TEST_CASE( "One element array" ) {    
    check( {1}, {1} );
}

TEST_CASE( "Sorted array" ) {    
    check( {1, 2, 3}, {1, 2, 3} );
}

TEST_CASE( "Unsorted array" ) { 
    check( {4, -5, 1, 0, 3}, {-5, 0, 1, 3, 4} );
}

TEST_CASE( "Sorted array with duplicates" ) {    
    check( {-5, -5, 0, 2, 3, 3, 8}, {-5, -5, 0, 2, 3, 3, 8} );
}

TEST_CASE( "Unsorted array with duplicates" ) {    
    check( {4, 2, 4, -1, 0, 3, -1}, {-1, -1, 0, 2, 3, 4, 4} );
}

TEST_CASE( "Big array" ) {    
    check( {4, -2, 5, 0, 2, 120, 11, 6, -3, -67, 9, -21, 11}, {-67, -21, -3, -2, 0, 2, 4, 5, 6, 9, 11, 11, 120} );
}
