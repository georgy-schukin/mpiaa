#pragma once

#include <string>

class TreeNode {
public:
    TreeNode() {}
    TreeNode(char symbol, int weight, TreeNode *left = nullptr, TreeNode *right = nullptr):
        symbol(symbol),
        weight(weight),
        left(left),
        right(right) {
    }

    bool isLeaf() const {
        return !left && !right;
    }

public:
    char symbol {0};
    int weight {0};
    TreeNode *left {nullptr};
    TreeNode *right {nullptr};
};

TreeNode* buildTree();
void deleteTree(const TreeNode *root);

std::string encode(const TreeNode *tree, const std::string &str);
std::string decode(const TreeNode *tree, const std::string &code_str);
