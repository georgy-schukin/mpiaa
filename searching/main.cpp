#include "search.h"
#include "file_io.h"
#include "timer.h"

#include <iostream>
#include <exception>
#include <ctime>

Dictionary buildDictionary(const std::string &input_file) {
    const PersonCollection persons = readFromFile<PersonCollection>(input_file);
    std::cout << "Adding " << persons.size() << " elements in the dictionary..." << std::endl;
    Dictionary dict;

    Timer timer;
    doBuild(persons, dict);
    const double duration = timer.getDuration();

    std::cout << "Building the dictionary took " << duration << " seconds" << std::endl;
    return dict;
}

void searchInDictionary(const Dictionary &dict, const std::string &keys_file) {
    const KeyCollection keys = readFromFile<KeyCollection>(keys_file);
    std::cout << "Searching " << keys.size() << " keys in the dictionary..." << std::endl;

    Timer timer;
    const int found = doSearch(dict, keys);
    const double duration = timer.getDuration();

    std::cout << "Searching took " << duration << " seconds" <<
                 ", keys found: " << found << std::endl;
}

void doWork(const std::string &input_file, const std::string &keys_file) {
    const Dictionary dict = buildDictionary(input_file);
    searchInDictionary(dict, keys_file);
}

int main(int argc, char **argv) {
    std::string input = argc > 1 ? argv[1] : "input_1e3.txt";
    std::string keys = argc > 2 ? argv[2] : "keys.txt";

    try {
        doWork(input, keys);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return -1;
    }
    return 0;
}

