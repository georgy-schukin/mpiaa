#include <algorithm>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstdio>
#include <cmath>

std::vector<int> gen_random_array(int size) {
	std::vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand();		
	}
	return result;
}

void measure(int size) {	
	std::vector<int> data = gen_random_array(size);
	
	auto t1 = std::chrono::high_resolution_clock::now();
	std::sort(data.begin(), data.end());
	auto t2 = std::chrono::high_resolution_clock::now();	
	
	double time = std::chrono::duration<double>(t2 - t1).count();	
	
	printf("N: %d, time: %.5f sec\n", size, time);
}

int main() {
	for (int i = 1; i < 6; i++) {
		measure(pow(10, i));
	}
	return 0;
}
