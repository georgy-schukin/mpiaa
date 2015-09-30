#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <string>

template<class ContainerType>
ContainerType readFromFile(const std::string &filename) {
    std::ifstream in(filename.c_str());
    if (!in.is_open()) {
        throw std::runtime_error("Cannot open file " + filename);
    }

    ContainerType data;
    typename ContainerType::value_type elem;
    while (in >> elem) {
        data.push_back(elem);
    }
    return data;
}

template<class ContainerType>
void writeToFile(const std::string &filename, const ContainerType &data) {
    std::ofstream out(filename.c_str());
    if (!out.is_open()) {
        throw std::runtime_error("Cannot open file " + filename);
    }

    for (typename ContainerType::const_iterator it = data.begin(); it != data.end(); it++) {
        out << *it << "\n";
    }
}
