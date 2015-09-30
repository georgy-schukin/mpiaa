#include "sort.h"
#include "file_io.h"

#include <iostream>
#include <exception>
#include <ctime>

void doWork(const std::string &input_file, const std::string &output_file) {
    ArrayType data = readFromFile<ArrayType>(input_file);

    std::cout << "Sorting " << data.size() << " elements..." << std::endl;
    std::clock_t start_time = std::clock();

    ArrayType sorted_data = doSort(data);

    std::clock_t end_time = std::clock();
    const double duration = (end_time - start_time)/double(CLOCKS_PER_SEC);
    std::cout << "Sorting took " << duration << " seconds" << std::endl;

    writeToFile(output_file, sorted_data);
}

int main(int argc, char **argv) {
    std::string input = argc > 1 ? argv[1] : "input_1e3.txt";
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

