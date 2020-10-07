#include "../catch.hpp"

#include "dictionary.h"

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
    d.set("big", "grande");
    d.set("BIG", "GRANDE");
    CHECK( d.size() == 2 );
    CHECK( d.get("big") == "grande" );
    CHECK( d.get("BIG") == "GRANDE" );
}

TEST_CASE( "Anagrams" ) {    
    Dictionary d;
    d.set("abc", "uno");
    d.set("bac", "dos");
    d.set("cba", "tres");
    CHECK( d.size() == 3 );
    CHECK( d.get("abc") == "uno" );
    CHECK( d.get("bac") == "dos" );
    CHECK( d.get("cba") == "tres" );
}

TEST_CASE( "Same first letter" ) {    
    Dictionary d;
    d.set("hello", "hola");
    d.set("house", "casa");
    d.set("human", "humano");
    CHECK( d.size() == 3 );
    CHECK( d.get("hello") == "hola" );
    CHECK( d.get("house") == "casa" );
    CHECK( d.get("human") == "humano" );
}

TEST_CASE( "User hash function" ) {    
    auto my_hash = [](const std::string &s) { return s.size(); };
    Dictionary d(10, my_hash);
    d.set("s1", "Short string");
    d.set("s2", "Another short string");
    d.set("long", "Long string");    
    d.set("long", "Longer string");    
    d.set("long long long", "Very very long string");    
    CHECK( d.size() == 4 );
    CHECK( d.get("s2") == "Another short string" );    
    CHECK( d.get("long long long") == "Very very long string" );
}
