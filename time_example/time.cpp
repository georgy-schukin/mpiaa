#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
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
    
    std::cout << "N: " << size << ", time: " << time << std::endl;
}

int main(int argc, char **argv) {
    int max_pow = argc > 1 ? std::stoi(argv[1]) : 6;
    
	for (int i = 1; i <= max_pow; i++) {
		measure(pow(10, i));
	}

	return 0;
}
