#include "set.h"

// Node of a binary tree.
struct TreeNode {
    int item;
    TreeNode *left;
    TreeNode *right;
       
    TreeNode() : item(0), left(nullptr), right(nullptr) {}
    TreeNode(int item) : item(item), left(nullptr), right(nullptr) {}
};

// Auxilary functions
void tree_delete(TreeNode *node) {
    if (!node) {
        return;
    }
    tree_delete(node->left);
    tree_delete(node->right);
    delete node;
}

int tree_size(const TreeNode *node) {
    if (!node) {
        return 0;
    }
    return 1 + tree_size(node->left) + tree_size(node->right);
}

// Set methods
Set::Set() :
    root(nullptr) {
}

Set::~Set() {
    tree_delete(root);
}

int Set::size() const {
    // Return size (number of items) of the set.
    return tree_size(root);
}

void Set::insert(int item) {
    // Insert item into the set.
    // If item is in the set already, do nothing.
}

bool Set::find(int item) const {
    // Return true if item is in the set, false otherwise.
    return false;
}
