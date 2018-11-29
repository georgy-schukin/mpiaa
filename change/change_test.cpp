#define CATCH_CONFIG_MAIN

#include "../catch.hpp"

#include "change.h"

#include <algorithm>

std::vector<int> sorted(const std::vector<int> &v) {
    auto vs = v;
    std::sort(vs.begin(), vs.end());
    return vs;
}

TEST_CASE( "Zero amount", "[get_change]" ) {
    REQUIRE( sorted(get_change({1}, 0)) == sorted({}) );
}

TEST_CASE( "One denomination", "[get_change]" ) {
    REQUIRE( sorted(get_change({1}, 3)) == sorted({1, 1, 1}) );
}

TEST_CASE( "Several denominations", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 2, 3}, 3)) == sorted({3}) );
}

TEST_CASE( "Several denominations, many coins", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 2, 3}, 5)) == sorted({3, 2}) );
}

TEST_CASE( "Several denominations, many coins 2", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 2, 3}, 7)) == sorted({3, 3, 1}) );
}

TEST_CASE( "Greedy must fail", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 4, 6}, 8)) == sorted({4, 4}) );
}

TEST_CASE( "Greedy works too", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 5, 10}, 27)) == sorted({10, 10, 5, 1, 1}) );
}

TEST_CASE( "Greedy works too 2", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 2, 5, 10}, 27)) == sorted({10, 10, 5, 2}) );
}

TEST_CASE( "Greedy works again", "[get_change]" ) {
    REQUIRE( sorted(get_change({1, 5, 9}, 27)) == sorted({9, 9, 9}) );
}

