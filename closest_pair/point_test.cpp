#include "point.h"

#include "../catch.hpp"

#include <cmath>

TEST_CASE( "Point distance" ) {
	CHECK( Point(2, 2).distance(Point(2, 3)) == 1 );
	CHECK( Point(3, 3).distance(Point(-1, 3)) == 4 );
	CHECK( Point(2.7, 1.5).distance(Point(4.7, 2.5)) == sqrt(5) );
}

TEST_CASE( "Point equal" ) {
	CHECK( Point(3, 2) == Point(3, 2) );		
	CHECK( Point(-2, 1) == Point(-2, 1) );	
	CHECK( Point(3.7, -4.9) == Point(3.7, -4.9) );	
}

TEST_CASE( "Point not equal" ) {
	CHECK( Point(3, 2) != Point(2, 3) );		
	CHECK( Point(-2, 1) != Point(-2, 1.5) );	
	CHECK( Point(3.7, -4.9) != Point(3.7, -4.85) );	
}

TEST_CASE( "Point less" ) {
	CHECK( Point(3, 2) < Point(3, 3) );		
	CHECK( Point(-2, 1) < Point(-2, 2) );	
	CHECK( Point(3.7, -4.9) < Point(3.7, -4.85) );	
}

TEST_CASE( "Point less or equal" ) {
	CHECK( Point(3, 2) <= Point(3, 3) );		
	CHECK( Point(2, 2) <= Point(2, 2) );
	CHECK( Point(-2, 1) <= Point(-2, 2) );	
	CHECK( Point(-2, -1) <= Point(-2, -1) );	
	CHECK( Point(3.7, -4.9) <= Point(3.7, -4.85) );	
	CHECK( Point(3.7, -4.9) <= Point(3.7, -4.9) );	
}