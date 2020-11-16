#include "../catch.hpp"

#include "activities.h"

#include <set>
#include <sstream>

using namespace std;

namespace Catch {
    template<> 
    struct StringMaker<Activity> {
        static string convert(const Activity &a) {
            ostringstream out;
            out << "{" << a.start << ", " << a.finish << "}";
            return out.str();
        } 
    };    
}

// Convert vector of activities to set for equality comparison.
set<Activity> to_set(const vector<Activity> &acts) {
    return set<Activity>(acts.begin(), acts.end());    
}

TEST_CASE( "Empty", "[activity]" ) {
    CHECK( to_set(get_max_activities({})) == to_set({}) );
}

TEST_CASE( "One activity", "[activity]" ) {
    CHECK( to_set(get_max_activities({ {2, 3} })) == to_set({ {2, 3} }) );
}

TEST_CASE( "Two compatibles", "[activity]" ) {
    CHECK( to_set(get_max_activities({ {3, 4}, {2, 3} })) == to_set({ {2, 3}, {3, 4} }) );
}

TEST_CASE( "Two overlaps", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 5}, {3, 4} }));
    CHECK( (answer == to_set({ {2, 5} }) || answer == to_set({ {3, 4} })) );
}

TEST_CASE( "Two incompatibles", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {3, 6}, {2, 5} }));
    CHECK( (answer == to_set({ {2, 5} }) || answer == to_set({ {3, 6} })) );
}

TEST_CASE( "Three activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {5, 8} }));
    CHECK( answer == to_set({ {1, 4}, {5, 8} }) );
}

TEST_CASE( "Four activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {7, 10}, {5, 8} }));
    CHECK( (answer == to_set({ {1, 4}, {5, 8} }) || answer == to_set({ {2, 6}, {7, 10} })) );
}

TEST_CASE( "Five activities", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {2, 6}, {1, 4}, {7, 10}, {5, 8}, {9, 12} }));
    CHECK( answer == to_set({ {1, 4}, {5, 8}, {9, 12} }) );
}

TEST_CASE( "Big one", "[activity]" ) {
    const auto answer = to_set(get_max_activities({ {3, 5}, {1, 4}, {5, 7}, {0, 6},
                                                    {3, 9}, {5, 9}, {6, 11}, {4, 10},
                                                    {8, 12}, {2, 14}, {12, 16} }));
    CHECK( (answer == to_set({ {1, 4}, {5, 7}, {8, 12}, {12, 16} }) ||
              answer == to_set({ {3, 5}, {5, 7}, {8, 12}, {12, 16}})) );
}
