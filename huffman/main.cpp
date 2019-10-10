#include "huffman.h"

#include <iostream>

int main() {
    const auto *tree = buildTree();
    while (true) {
        std::cout << "Input the string to encode: ";
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }
        try {
            auto encoded = encode(tree, input);
            std::cout << "Encoded string is: " << encoded << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
    deleteTree(tree);
    return 0;
}
