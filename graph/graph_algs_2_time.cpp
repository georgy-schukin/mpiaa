#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "graph.h"
#include "graph_algs_2.h"

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
    const auto comps = connected_components(g);
    double cc_time = t.getTime();

    t.start();
    const int repeats = 100;
    for (int i = 0; i < repeats; i++) {
        const auto path = shortest_path(g, rand() % size, rand() % size);
    }
    double sp_time = t.getTime() / repeats;
    
    printf("N: %8d, cc time: %10.5f sec, sp time: %10.5f sec (%d components)\n", 
        size, cc_time, sp_time, (int)comps.size());
}

int main() {
    for (int i = 1; i < 6; i++) {
        measure(pow(10, i));
    }
    return 0;
}
