#pragma once

#include <string>
#include <functional>
#include <vector>
#include <list>

using HashFunction = std::function<int(const std::string&)>;

/**
* Dictionary that maps strings to other strings.
*/
class Dictionary {
public:
    Dictionary(int num_of_buckets = 1000, HashFunction hash = std::hash<std::string> {});
    ~Dictionary();
    
    /// Set/replace value for the key.
    void set(const std::string &key, const std::string &value);
    
    /// Get value for the key or empty string if there is no such key.    
    std::string get(const std::string &key) const;
    
    /// Get number of items (keys) in the dictionary.
    int size() const;

private:    
    using KeyValue = std::pair<std::string, std::string>; 

    std::vector<std::list<KeyValue>> table;

    HashFunction hash_function;    
    
    // Add other private methods and fields here.
};
