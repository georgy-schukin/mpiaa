#pragma once

class Activity {
public:
    Activity() = default;        
    Activity(int start, int finish) :
        start(start), finish(finish) {
    }        

    bool operator<(const Activity &a) const;
    bool operator==(const Activity &a) const;

public:
    int start {0};
    int finish {0};
};
