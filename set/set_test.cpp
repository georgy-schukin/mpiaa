#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "set.h"

TEST_CASE( "Empty set" ) {    
	Set s;
    REQUIRE( s.size() == 0 );
	REQUIRE_FALSE( s.find(1) );
}

TEST_CASE( "Insert one item" ) {    
	Set s;
	s.insert(1);
    REQUIRE( s.size() == 1 );
	REQUIRE( s.find(1) );
}

TEST_CASE( "Insert many items" ) {    
	Set s;
	s.insert(2);
	s.insert(1);
	s.insert(3);
    REQUIRE( s.size() == 3 );
	REQUIRE( s.find(2) );
	REQUIRE( s.find(1) );
	REQUIRE( s.find(3) );
	REQUIRE_FALSE( s.find(0) );
}

TEST_CASE( "Insert duplicates" ) {    
	Set s;
	s.insert(2);
	s.insert(2);
	s.insert(3);
    REQUIRE( s.size() == 2 );
	REQUIRE( s.find(2) );
	REQUIRE( s.find(3) );
	REQUIRE_FALSE( s.find(0) );
}


