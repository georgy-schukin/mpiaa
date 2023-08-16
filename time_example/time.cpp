#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>
#include <cstdlib>
#include <cmath>

using namespace std;
using namespace std::chrono;

vector<int> gen_random_array(int size) {
	vector<int> result(size);
	for (int i = 0; i < size; i++) {
		result[i] = rand();		
	}
	return result;
}

void measure(int size) {	
	auto data = gen_random_array(size);
	
	auto t1 = steady_clock::now();
	sort(data.begin(), data.end());
	auto t2 = steady_clock::now();	
	
	auto time = duration<double>(t2 - t1).count();	
    
    cout << "N: " << size << ", time: " << time << endl;
}

int main(int argc, char **argv) {
    int max_pow = argc > 1 ? stoi(argv[1]) : 6;
    
	for (int i = 1; i <= max_pow; i++) {
		measure(pow(10, i));
	}

	return 0;
}
