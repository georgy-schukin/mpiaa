#include "huffman.h"

Alphabet defaultAlphabet() {
    Alphabet alphabet;
    for (char c = 'a'; c <= 'z'; c++) {
        alphabet[c] = 5.0;
    }
    for (char c = 'A'; c <= 'Z'; c++) {
        alphabet[c] = 2.0;
    }
    for (char c: std::string(" \"'0123456789!?@#$%^&*()-+,.~<>`\t\n\r")) {
        alphabet[c] = 1.0;
    }
    return alphabet;
}

Alphabet getAlphabet(const std::string &text) {
    Alphabet alphabet;
    // Your implementation here.
    return alphabet;
}

TreeNode* buildTree(const Alphabet &alphabet) {
    // Your implementation here.
    return nullptr;
}

void deleteTree(TreeNode *root) {
    if (!root) {
        return;
    }
    if (root->left) {
        deleteTree(root->left);
    }
    if (root->right) {
        deleteTree(root->right);
    }
    delete root;
}

HuffmanCoder::HuffmanCoder(const Alphabet &alphabet) {
    tree = buildTree(alphabet);
    code_table = getCodeTable(tree);
}

HuffmanCoder::HuffmanCoder(const std::string &text) :
    HuffmanCoder(getAlphabet(text)) {        
}

HuffmanCoder::~HuffmanCoder() {
    if (tree) {
        deleteTree(tree);
    }
}

HuffmanCode HuffmanCoder::encode(const std::string &str) { 
    HuffmanCode result = "";
    for (auto c: str) {
        try {
            result += code_table.at(c);
        }
        catch (const std::out_of_range&) {
            throw std::runtime_error(std::string("Cannot encode character ") + c);
        }
    }
    return result;
}

std::string HuffmanCoder::decode(const HuffmanCode &code) {
    std::string result = "";
    TreeNode *current = tree;
    for (auto c: code) {
        if (c == '0') {
            if (current->left) {
                current = current->left;
            } else {
                throw std::runtime_error("Failed to decode");
            }
        } else if (c == '1') {
            if (current->right) {
                current = current->right;
            } else {
                throw std::runtime_error("Failed to decode");
            }
        } else {
            throw std::runtime_error("Incorrect code character: " + c);
        }        
        if (current->isLeaf()) {
            result += current->symbol;
            current = tree;
        }
    }
    return result;
}

void addToCodeTable(const TreeNode *tree, CodeTable &table, const HuffmanCode &code) {
    if (!tree) {
        return;
    }
    if (tree->isLeaf()) {
        table[tree->symbol] = code;
        return;
    }
    addToCodeTable(tree->left, table, code + '0');
    addToCodeTable(tree->right, table, code + '1');
}

CodeTable HuffmanCoder::getCodeTable(const TreeNode *root) {
    CodeTable table;
    addToCodeTable(root, table, "");
    return table;
}
