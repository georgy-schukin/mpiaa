#pragma once

#include <vector>

class Activity {
public:
    Activity() = default;        
    Activity(int start, int finish) :
        start(start), finish(finish) {
    }    

public:
    int start {0};
    int finish {0};
};

// Get a maximum-size subset of mutually compatible activities.
std::vector<Activity> get_max_activities(const std::vector<Activity> &activities);