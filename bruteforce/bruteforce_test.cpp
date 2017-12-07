#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "bruteforce.h"
#include "sha256.h"

#include <set>

namespace {
    template <class T>
    void check_matched(const typename std::vector<T> &v1, const typename std::vector<T> &v2) {
        CHECK ( v1.size() == v2.size() );        
        // Sort and remove duplicates by converting to sets.
        typename std::set<T> s1(v1.begin(), v1.end());
        typename std::set<T> s2(v2.begin(), v2.end());
        // Convert back to vectors to enable pretty print in Catch. 
        typename std::vector<T> vm1(s1.begin(), s1.end());
        typename std::vector<T> vm2(s2.begin(), s2.end());
        CHECK ( vm1 == vm2);
    }
}

TEST_CASE( "No symbols", "[all_words]" ) {
    check_matched(all_words("", 1), {});
}

TEST_CASE( "Zero max length", "[all_words]" ) {
    check_matched(all_words("a", 0), {});
}

TEST_CASE( "No symbols and zero max length", "[all_words]" ) {
    check_matched(all_words("", 0), {});
}

TEST_CASE( "One symbol size 1", "[all_words]" ) {
    check_matched(all_words("a", 1), {"a"});
}

TEST_CASE( "One symbol size 2", "[all_words]" ) {
    check_matched(all_words("a", 2), {"a", "aa"});
}

TEST_CASE( "One symbol size 3", "[all_words]" ) {
    check_matched(all_words("a", 3), {"a", "aa", "aaa"});
}

TEST_CASE( "Two symbols size 1", "[all_words]" ) {
    check_matched(all_words("ab", 1), {"a", "b"});
}

TEST_CASE( "Two symbols size 2", "[all_words]" ) {
    check_matched(all_words("ab", 2), {"a", "b", "aa", "ab", "ba", "bb"});
}

TEST_CASE( "Two symbols size 3", "[all_words]" ) {
    check_matched(all_words("ab", 3), {"a", "b", 
                                        "aa", "ab", "ba", "bb", 
                                        "aaa", "aab", "aba", "abb", "baa", "bab", "bba", "bbb"});
}

TEST_CASE( "Three symbols size 1", "[all_words]" ) {
    check_matched(all_words("abc", 1), {"a", "b", "c"});
}

TEST_CASE( "Three symbols size 2", "[all_words]" ) {
    check_matched(all_words("abc", 2), {"a", "b", "c", 
                                         "aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc"});
}

TEST_CASE( "Three symbols size 3", "[all_words]" ) {
    check_matched(all_words("abc", 3), {"a", "b", "c", 
                                         "aa", "ab", "ac", "ba", "bb", "bc", "ca", "cb", "cc",
                                         "aaa", "aab", "aac", "aba", "abb", "abc", "aca", "acb", "acc",
                                         "baa", "bab", "bac", "bba", "bbb", "bbc", "bca", "bcb", "bcc",
                                         "caa", "cab", "cac", "cba", "cbb", "cbc", "cca", "ccb", "ccc"});
}

TEST_CASE( "Empty alphabet", "[bruteforce]" ) {
    CHECK( bruteforce("", 1, sha256("hello")) == "" );
}

TEST_CASE( "Zero length password", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 0, sha256("hello")) == "" );
}

TEST_CASE( "Password max length 1", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 1, sha256("b")) == "b" );
}

TEST_CASE( "Password max length 2", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 2, sha256("ab")) == "ab" );
    CHECK( bruteforce("abc", 2, sha256("c")) == "c" );
}

TEST_CASE( "Password max length 3", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 3, sha256("bac")) == "bac" );
    CHECK( bruteforce("abc", 3, sha256("ba")) == "ba" );
    CHECK( bruteforce("abc", 3, sha256("a")) == "a" );
}

TEST_CASE( "Missing symbols in alphabet", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 3, sha256("daddy")) == "" );
    CHECK( bruteforce("abc", 3, sha256("$#!")) == "" );
}

TEST_CASE( "Max length is too small", "[bruteforce]" ) {
    CHECK( bruteforce("abc", 3, sha256("baca")) == "" );
    CHECK( bruteforce("abc", 2, sha256("cba")) == "" );
}

