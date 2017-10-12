#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "set.h"

typedef std::chrono::high_resolution_clock hrc;

namespace {
    class Timer {
    public:
        Timer() {}

        void start() {
            begin = hrc::now();
        }

        double getTime() {
	        auto end = hrc::now();		
	        return std::chrono::duration<double>(end - begin).count();	
        }

    private:
        hrc::time_point begin;
    };
}

std::vector<int> gen_random_array(int size) {
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand() % size;
	}
    return result;
}

std::vector<int> gen_shuffled_array(int size) {
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = i;
	}
    for (int i = 0; i < size; i++) {
        std::swap(result[rand() % size], result[rand() % size]);
    }
	return result;
}

int linear_search(const std::vector<int> &data, const std::vector<int> &keys) {
	int found = 0;
	for (const auto &key: keys) {
		auto it = std::find(data.begin(), data.end(), key);
		if (it != data.end()) {
			found++;
		}
	}
	return found;
}

int set_search(const Set &s, const std::vector<int> &keys) {
	int found = 0;
	for (const auto &key: keys) {	
		if (s.find(key)) {
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
	
	Set s;
	for (const auto &item: data) {
		s.insert(item);
	}
	
    t.start();
	int set_found = set_search(s, keys);
	double set_time = t.getTime();
	
	printf("N: %d, keys: %d, lin. search time: %.5f sec (%d found), set search time: %.5f (%d found)\n", 
		size, num_of_keys, lin_time, lin_found, set_time, set_found);
}

int main() {
	for (int i = 1; i < 6; i++) {
		measure(pow(10, i), 1000);
	}
	return 0;
}
