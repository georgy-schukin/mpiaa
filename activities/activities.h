#pragma once

#include <vector>

class Activity {
public:
    Activity() = default;
    Activity(const Activity&) = default;
    Activity(int start, int finish) :
        start(start), finish(finish) {
    }
    ~Activity() = default;

public:
    int start;
    int finish;
};

// Get a maximum-size subset of mutually compatible activities.
std::vector<Activity> get_max_activities(const std::vector<Activity> &activities);