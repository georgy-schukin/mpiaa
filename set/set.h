#pragma once

/**
* Set of integer numbers.
*/
class Set {
public:
    Set();
    ~Set();

    /// Get size of the set.
    int size() const;
    
    /// Insert item into the set.
    void insert(int item);
    
    /// Check if item is in the set.
    bool find(int item) const;    
           
private:    
    struct TreeNode *root;
};
