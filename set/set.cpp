#include "set.h"

TreeNode::TreeNode() :
	left(nullptr), right(nullptr) {
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

bool set_find(Set *s, int item) {
	return false;
}

void set_insert(Set *s, int item) {
}

int set_size(Set *s) {
}