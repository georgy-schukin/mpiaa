#include "../catch.hpp"

#include "lcs.h"


TEST_CASE( "Both strings are empty" ) {
    CHECK( lcs("", "") == "" );
}

TEST_CASE( "One string is empty" ) {
    CHECK( lcs("", "abcd") == "" );
    CHECK( lcs("abcd", "") == "" );
}

TEST_CASE( "Equal strings" ) {
    CHECK( lcs("abcd", "abcd") == "abcd" );
}

TEST_CASE( "Substring" ) {
    CHECK( lcs("abab", "ab") == "ab" );
}

TEST_CASE( "Substring in the middle" ) {
    CHECK( lcs("xyaban", "abarab") == "aba" );
}

TEST_CASE( "Subsequences" ) {
    CHECK( lcs("nahybser", "iunkayxbis") == "naybs" );
    CHECK( lcs("z1artunx", "yz21rx") == "z1rx" );
    CHECK( lcs("z1arxzyx1a", "yz21rx") == "z1rx" );
    CHECK( lcs("yillnum", "numyjiljil") == "yill" );
}

TEST_CASE( "Reverse subsequence" ) {
    auto result = lcs("xablar", "ralbax");
    CHECK( (result == "aba" || result == "ala") ); 
}
