#include "../catch.hpp"

#include <algorithm>
#include <vector>

void check(const std::vector<int> &input, const std::vector<int> &expected) {
    auto output = input;
    std::sort(output.begin(), output.end());
    REQUIRE (output == expected);
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

