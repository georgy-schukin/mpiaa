#pragma once

#include <string>

/**
* Dictionary that maps strings to strings.
*/
class Dictionary {
public:
    Dictionary();
    ~Dictionary();
    
    /// Set value for the key.
    /// Replace old value with the new one if the key already exists.
    void set(const std::string &key, const std::string &value);
    
    /// Get value for the key.
    /// Returns empty string if there is no such key.
    std::string get(const std::string &key) const;
    
    /// Get number of items (keys) in the dictionary.
    int size() const;
};
