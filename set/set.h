#pragma once

/**
* Set of integer numbers.
*/
class Set {
public:
    Set();
    ~Set();
    
    /// Insert the element into the set.
    void insert(int elem);
    
    /// Check if the element is in the set.
    bool find(int elem) const;    

    /// Get size of the set.
    int size() const;
           
private:    
    // Private members go here.
};
