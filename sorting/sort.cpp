#include "sort.h"

#include <algorithm>
#include <iostream>
#include <exception>
#include <ctime>

typedef int ElemType;
typedef std::vector<ElemType> ArrayType;

void doSort(ArrayType &data) {
    std::sort(data.begin(), data.end());
}

void doWork(const std::string &input_file, const std::string &output_file) {
    ArrayType data = readFromFile<ElemType, ArrayType>(input_file);

    std::cout << "Sorting " << data.size() << " elements..." << std::endl;
    std::clock_t start_time = std::clock();

    doSort(data);

    std::clock_t end_time = std::clock();
    const double duration = (end_time - start_time)/double(CLOCKS_PER_SEC);
    std::cout << "Sorting took " << duration << " seconds" << std::endl;

    writeToFile<ElemType>(output_file, data);
}

int main(int argc, char **argv) {
    std::string input = argc > 1 ? argv[1] : "input.txt";
    std::string output = argc > 2 ? argv[2] : "output.txt";

    try {
        doWork(input, output);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}
