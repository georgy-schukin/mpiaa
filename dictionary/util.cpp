#include "util.h"

#include <cstdlib>
#include <algorithm>

std::string random_string(int size) {
	static const std::string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	return random_string(size, alphabet);
}

std::string random_string(int size, const std::string &alphabet) {	 	    
    std::string result;
    auto random_char = [&]() { return alphabet[rand() % alphabet.size()]; };
    std::generate_n(std::back_inserter(result), size, random_char);
    return result;
}
