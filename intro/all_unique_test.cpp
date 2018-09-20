#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "../catch.hpp"

#include "all_unique.h"

TEST_CASE( "Empty array", "[all_unique]" ) {    
    REQUIRE( !all_unique(NULL, 0) );
}

TEST_CASE( "One element array", "[all_unique]" ) {    
    int data[] = {1};
    REQUIRE( all_unique(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Array without duplicates", "[all_unique]" ) {    
    int data[] = {1, 2, 3, 6, 7, 9};
    REQUIRE( all_unique(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Unsorted array without duplicates", "[all_unique]" ) {    
    int data[] = {3, 2, 0, 6, 1, 9};
    REQUIRE( all_unique(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Array with duplicates", "[all_unique]" ) {    
    int data[] = {1, 2, 2, 6, 9, 9};
    REQUIRE( !all_unique(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Unsorted array with duplicates", "[all_unique]" ) {    
    int data[] = {2, 2, 1, 6, 0, 9, 9};
    REQUIRE( !all_unique(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Array with separated duplicates", "[all_unique]" ) {    
    int data[] = {1, 2, 3, 2, 5, 9, 1};
    REQUIRE( !all_unique(data, sizeof(data)/sizeof(int)) );
}

