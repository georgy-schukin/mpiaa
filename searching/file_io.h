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
        data.insert(data.end(), elem);
    }
    return data;
}
