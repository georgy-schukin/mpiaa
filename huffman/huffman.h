#pragma once

#include <string>
#include <map>

using Alphabet = std::map<char, double>;
using HuffmanCode = std::string;
using CodeTable = std::map<char, HuffmanCode>;

// Return default universal alphabet.
Alphabet defaultAlphabet();

// Construct an alphabet from given text.
Alphabet getAlphabet(const std::string &text);

// A node of a Huffman tree.
struct TreeNode {
    char symbol {0};
    double weight {0.0};
    TreeNode *left {nullptr};
    TreeNode *right {nullptr};

    TreeNode() {}
    TreeNode(char symbol, double weight, TreeNode *left = nullptr, TreeNode *right = nullptr):
        symbol(symbol),
        weight(weight),
        left(left),
        right(right) {
    }

    bool isLeaf() const {
        return !left && !right;
    }    
};

// Build a Huffman tree from given alphabet.
TreeNode* buildTree(const Alphabet &alphabet);
// Destroy given Huffman tree.
void deleteTree(TreeNode *root);

// Coder to encode/decode strings using Huffman codes.
class HuffmanCoder {
public:
    HuffmanCoder(const Alphabet &alphabet = defaultAlphabet());
    HuffmanCoder(const std::string &text);
    ~HuffmanCoder();

    HuffmanCode encode(const std::string &str);
    std::string decode(const HuffmanCode &code);

private:        
    CodeTable getCodeTable(const TreeNode *root);

private:
    TreeNode *tree = nullptr;  
    CodeTable code_table; 
};
