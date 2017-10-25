#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"

#include "dict.h"

TEST_CASE( "Empty dictionary" ) {
    Dictionary d;
    CHECK( d.size() == 0 );
    CHECK( d.get("hello") == "" );
}

TEST_CASE( "One item" ) {    
    Dictionary d;
    d.set("friend", "amigo");
    CHECK( d.size() == 1 );
    CHECK( d.get("friend") == "amigo" );    
}

TEST_CASE( "Several items" ) {    
    Dictionary d;
    d.set("friend", "amigo");
    d.set("dog", "perro");
    d.set("cat", "gato");
    CHECK( d.size() == 3 );
    CHECK( d.get("friend") == "amigo" );
    CHECK( d.get("dog") == "perro" );
    CHECK( d.get("cat") == "gato" );
}

TEST_CASE( "Duplicate keys" ) {    
    Dictionary d;
    d.set("beer", "beer");
    d.set("cat", "gato");
    d.set("beer", "cerveza");
    CHECK( d.size() == 2 );
    CHECK( d.get("beer") == "cerveza" );
}

TEST_CASE( "Duplicate values" ) {    
    Dictionary d;
    d.set("hello", "hola");
    d.set("friend", "amigo");
    d.set("hi", "hola");
    CHECK( d.size() == 3 );
    CHECK( d.get("hello") == "hola" );
    CHECK( d.get("hi") == "hola" );
}

TEST_CASE( "Case sensitive" ) {    
    Dictionary d;
    d.set("big", "largo");
    d.set("BIG", "GRANDE");
    CHECK( d.size() == 2 );
    CHECK( d.get("big") == "largo" );
    CHECK( d.get("BIG") == "GRANDE" );
}
