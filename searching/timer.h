#pragma once

#include <ctime>

class Timer {
public:
    Timer() {
        reset();
    }

    void reset() {
        start_time = std::clock();
    }

    double getDuration() {
        return (std::clock() - start_time)/double(CLOCKS_PER_SEC);
    }

private:
    std::clock_t start_time;
};
