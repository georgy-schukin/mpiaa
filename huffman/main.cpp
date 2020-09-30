#include "huffman.h"

#include <iostream>

int main() {
    HuffmanCoder coder {};
    while (true) {
        std::cout << "Input the string to encode: ";
        std::string input;
        std::getline(std::cin, input);
        if (input.empty()) {
            break;
        }
        try {
            auto encoded = coder.encode(input);
            std::cout << "Encoded string is: " << encoded << std::endl;
            auto decoded = coder.decode(encoded);
            std::cout << "Decoded string is: " << decoded << std::endl;
        }
        catch (const std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }    
    return 0;
}
