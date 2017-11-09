#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "graph.h"
#include "graph_algs.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
    class Timer {
    public:
        Timer() {}

        void start() {
            begin = hrc::now();
        }

        double getTime() {            
            return std::chrono::duration<double>(hrc::now() - begin).count();    
        }

    private:
        hrc::time_point begin;
    };
}

Graph gen_random_graph(int size) {
    Graph g;
    for (int i = 0; i < 10*size; i++) {
        g.add_edge(rand() % size, rand() % size);
    }
    return g;
}

void measure(int size) {    
    const auto g = gen_random_graph(size);

    Timer t;
        
    t.start();
    bool is_conn = is_connected(g);
    double time = t.getTime();
    
    printf("N: %d, time: %.5f sec (%s)\n", size, time, (is_conn ? "connected" : "not connected"));
}

int main() {
    for (int i = 1; i < 6; i++) {
        measure(pow(10, i));
    }
    return 0;
}
