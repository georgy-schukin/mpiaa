#pragma once

struct TreeNode {
	int item;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode();
	~TreeNode();
};

struct Set {
	TreeNode *root;
	
	Set();
	~Set();
};

bool set_find(Set *set, int item);
void set_insert(Set *set, int item);
int set_size(Set *s);