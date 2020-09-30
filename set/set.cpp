#include "set.h"

struct TreeNode {
	int elem;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;

	TreeNode(int elem = 0, TreeNode *left = nullptr, TreeNode *right = nullptr) :
		elem(elem), left(left), right(right) {			
	}
};

int treeSize(TreeNode *node) {
	if (!node) {
		return 0;
	}
	return 1 + treeSize(node->left) + treeSize(node->right);
}

void treeDelete(TreeNode *node) {
	if (!node) {
		return;
	}
	treeDelete(node->left);
	treeDelete(node->right);
	delete node;
}

Set::Set() {    
}

Set::~Set() {    
    treeDelete(root);
}

void Set::insert(int elem) {
    // Insert the element into the set.
    // If the element is in the set already, do nothing.

    // Your implementaton here.
}

bool Set::find(int elem) const {
    // Return true if the element is in the set, false otherwise.

    // Your implementaton here.
    return false;
}

int Set::size() const {
    // Return number of elements in the set.
    return treeSize(root);    
}
