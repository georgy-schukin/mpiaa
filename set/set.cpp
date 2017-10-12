#include "set.h"

TreeNode::TreeNode() :
	item(0), left(nullptr), right(nullptr) {
}

TreeNode::TreeNode(int item) :
	item(item), left(nullptr), right(nullptr) {
}

TreeNode::~TreeNode() {
	if (left) {
		delete left;
	}
	if (right) {
		delete right;
	}
}

Set::Set() :
	root(nullptr) {
}

Set::~Set() {
	if (root) {
		delete root;
	}
}

// Methods to implement

bool Set::find(int item) const {
    // Return true if item is in the set, false otherwise.
	return false;
}

void Set::insert(int item) {
    // Insert item into the set.
    // If the item is in the set already, do nothing.
}

int Set::size() const {
    // Return size (number of items) of the set.
	return 0;
}
