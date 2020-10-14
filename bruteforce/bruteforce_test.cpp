#include "../catch.hpp"

#include "bruteforce.h"
#include "sha256.h"


TEST_CASE( "Empty alphabet", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("hello"), "", 1) == "" );
}

TEST_CASE( "Zero length password", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("hello"), "abc", 0) == "" );
}

TEST_CASE( "Password max length 1", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("b"), "abc", 1) == "b" );
    CHECK( bruteforce(sha256("d"), "abc", 1) == "" );
}

TEST_CASE( "Password max length 2", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("ab"), "abc", 2) == "ab" );
    CHECK( bruteforce(sha256("c"), "abc", 2) == "c" );
    CHECK( bruteforce(sha256("d"), "abc", 2) == "" );
}

TEST_CASE( "Password max length 3", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("bac"), "abc", 3) == "bac" );
    CHECK( bruteforce(sha256("ba"), "abc", 3) == "ba" );
    CHECK( bruteforce(sha256("aba"), "abc", 3) == "aba" );
    CHECK( bruteforce(sha256("a"), "abc", 3) == "a" );
    CHECK( bruteforce(sha256("bad"), "abc", 3) == "" );
}

TEST_CASE( "Missing symbols in alphabet", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("daddy"), "abc", 3) == "" );
    CHECK( bruteforce(sha256("$#!"), "abc", 3) == "" );
}

TEST_CASE( "Max length is too small", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("baca"), "abc", 3) == "" );
    CHECK( bruteforce(sha256("cba"), "abc", 2) == "" );
}

TEST_CASE( "Small alphabet", "[bruteforce]" ) {
    CHECK( bruteforce(sha256("ddd"), "d", 4) == "ddd" );
    CHECK( bruteforce(sha256("dcd"), "d", 3) == "" );
}

