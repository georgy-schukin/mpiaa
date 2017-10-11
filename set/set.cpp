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
	return false;
}

void Set::insert(int item) {
}

int Set::size() const {
	return 0;
}
