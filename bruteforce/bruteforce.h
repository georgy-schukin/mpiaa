#pragma once

#include <string>
#include <vector>

// Try to crack password with given hash, using given alphabet and max password length.
std::string bruteforce(const std::string &password_hash, const std::string &alphabet, int max_length);