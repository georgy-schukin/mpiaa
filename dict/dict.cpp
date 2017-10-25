#include "dict.h"

// Methods to implement

Dictionary::Dictionary() {
    // Create inner data structures here.
}

Dictionary::~Dictionary() {
    // Delete inner data structures here.
}



void Dictionary::set(const std::string &key, const std::string &value) {
    // Insert key->value pair into the dictionary.
    // If such key already exists, replace old value with the new one.
}

std::string Dictionary::get(const std::string &key) const {
    // Return value for the key.
    // Return empty string if there is no such key.
    return "";
}

int Dictionary::size() const {
    // Return size (number of keys) of the dictionary.
    return 0;
}
