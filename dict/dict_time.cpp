#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "dict.h"

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

std::vector<std::string> gen_random_array(int size) {
    std::vector<std::string> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = std::to_string(rand() % size);
    }
    return result;
}

std::vector<std::string> gen_shuffled_array(int size) {
    std::vector<std::string> result(size);
    for (int i = 0; i < size; i++) {
        result[i] = std::to_string(i);
    }
    for (int i = 0; i < size; i++) {
        std::swap(result[rand() % size], result[rand() % size]);
    }
    return result;
}

int linear_search(const std::vector<std::string> &data, const std::vector<std::string> &keys) {
    int found = 0;
    for (const auto &key: keys) {
        auto it = std::find(data.begin(), data.end(), key);
        if (it != data.end()) {
            found++;
        }
    }
    return found;
}

int dict_search(const Dictionary &d, const std::vector<std::string> &keys) {
    int found = 0;
    for (const auto &key: keys) {    
        if (d.get(key) != "") {
            found++;
        }
    }
    return found;
}

void measure(int size, int num_of_keys) {
    const auto data = gen_shuffled_array(size);
    const auto keys = gen_random_array(num_of_keys);

    Timer t;
        
    t.start();
    int lin_found = linear_search(data, keys);
    double lin_time = t.getTime();
    
    Dictionary d;
    for (const auto &item: data) {
        d.set(item, "item");
    }
    
    t.start();
    int dict_found = dict_search(d, keys);
    double dict_time = t.getTime();
    
    printf("N: %d, keys: %d, lin. search time: %.5f sec (%d found), dict search time: %.5f (%d found)\n", 
        size, num_of_keys, lin_time, lin_found, dict_time, dict_found);
}

int main() {
    for (int i = 1; i < 6; i++) {
        measure(pow(10, i), 1000);
    }
    return 0;
}
