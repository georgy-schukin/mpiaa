#include "../catch.hpp"

#include "set.h"

TEST_CASE( "Empty set" ) {    
    Set s;    
    CHECK( s.size() == 0 );
    CHECK_FALSE( s.find(1) );    
}

TEST_CASE( "One item" ) {    
    Set s;
    s.insert(1);    
    CHECK( s.size() == 1 );
    CHECK( s.find(1) );    
}

TEST_CASE( "Several items" ) {    
    Set s;
    s.insert(2);
    s.insert(1);
    s.insert(3);    
    CHECK( s.size() == 3 );
    CHECK( s.find(2) );
    CHECK( s.find(1) );
    CHECK( s.find(3) );
    CHECK_FALSE( s.find(0) );    
}

TEST_CASE( "Duplicate items" ) {    
    Set s;
    s.insert(2);
    s.insert(2);
    s.insert(3);    
    CHECK( s.size() == 2 );
    CHECK( s.find(2) );
    CHECK( s.find(3) );
    CHECK_FALSE( s.find(1) );    
}

TEST_CASE( "Many items" ) { 
    Set s;
    s.insert(5);
    s.insert(3);
    s.insert(6);
    s.insert(4);
    s.insert(3);
    s.insert(2);    
    CHECK( s.size() == 5 );
    CHECK( s.find(5) );
    CHECK( s.find(3) );
    CHECK( s.find(2) );
    CHECK_FALSE( s.find(10) ); 
}

TEST_CASE( "Negative items" ) { 
    Set s;
    s.insert(0);
    s.insert(-2);
    s.insert(-1);
    s.insert(-2);
    s.insert(1);    
    CHECK( s.size() == 4 );
    CHECK( s.find(-1) );
    CHECK( s.find(1) );    
    CHECK( s.find(-2) );    
    CHECK_FALSE( s.find(2) );    
}
