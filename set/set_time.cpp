#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstdio>

#include "set.h"

std::vector<int> gen_random_array(int size) {
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand();		
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
	const auto data = gen_random_array(size);
	const auto keys = gen_random_array(keys);	
		
	auto t1 = std::chrono::high_resolution_clock::now();
	int lin_found = linear_search(data, keys);
	auto t2 = std::chrono::high_resolution_clock::now();		
	double lin_time = std::chrono::duration<double>(t2 - t1).count();	
	
	Set s;
	for (const auto &item: data) {
		s.insert(item);
	}
	
	t1 = std::chrono::high_resolution_clock::now();
	int set_found = set_search(s, keys);
	t2 = std::chrono::high_resolution_clock::now();		
	double set_time = std::chrono::duration<double>(t2 - t1).count();	
	
	printf("N: %d, keys: %d, lin. search time: %.5f sec (%d found), set search time: %.5f (%d found)\n", 
		size, num_of_keys, lin_time, lin_found, set_time, set_found);
}

int main() {
	for (int i = 1; i < 6; i++) {
		measure(pow(10, i), 1000);
	}
	return 0;
}
