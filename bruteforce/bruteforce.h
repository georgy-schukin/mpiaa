#pragma once

#include <string>
#include <vector>

// Generate all possible words with symbols from alphabet, with length up to max length.
std::vector<std::string> all_words(const std::string &alphabet, int max_length);

// Try to crack password with given hash, using given alphabet and max password length.
std::string bruteforce(const std::string &alphabet, int max_length, const std::string &password_hash);