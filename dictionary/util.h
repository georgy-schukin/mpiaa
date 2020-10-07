#pragma once

#include <string>

// Generate random string of given size.
std::string random_string(int size);

// Generate random string of given size from given alphabet.
std::string random_string(int size, const std::string &alphabet);