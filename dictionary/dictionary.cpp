#include "dictionary.h"

Dictionary::Dictionary(int num_of_buckets, HashFunction hash) : 
table(num_of_buckets), hash_function(hash) {    
}

Dictionary::~Dictionary() {
}

void Dictionary::set(const std::string &key, const std::string &value) {
    // Insert key-value pair into the dictionary.
    // If such key already exists, replace old value with the new one.
}

std::string Dictionary::get(const std::string &key) const {
    // Return value for the key.
    // Return empty string if there is no such key.
    return "";
}

int Dictionary::size() const {
    // Return size of the dictionary, i.e. number of key-value pairs.    
    int size = 0;
    for (const auto &bucket: table) {
    	size += bucket.size();    	
    }
    return size;
}

