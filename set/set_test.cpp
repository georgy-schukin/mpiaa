#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "set.h"

TEST_CASE( "Empty set" ) {    
	Set s;
    REQUIRE( set_size(&s) == 0 );
}


