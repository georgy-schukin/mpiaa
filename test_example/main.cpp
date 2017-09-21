#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "function.h"

TEST_CASE( "Empty array", "[is_sorted]" ) {    
    REQUIRE( is_sorted(NULL, 0) );
}

TEST_CASE( "One element array", "[is_sorted]" ) {    
    int data[] = {1};
    REQUIRE( is_sorted(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Sorted array", "[is_sorted]" ) {    
    int data[] = {1, 2, 6, 9};
    REQUIRE( is_sorted(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Unsorted array", "[is_sorted]" ) { 
    int data[] = {1, 2, 0, 9, 3};
    REQUIRE( !is_sorted(data, sizeof(data)/sizeof(int)) );
}

TEST_CASE( "Sorted array with duplicates", "[is_sorted]" ) {    
    int data[] = {1, 2, 2, 6, 9, 9};
    REQUIRE( is_sorted(data, sizeof(data)/sizeof(int)) );
}

