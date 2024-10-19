#include <iostream>
#include <string>
#include "binary_to_hex.h"

int main() {
    std::string binary;
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    try {
        std::string hex = binary_to_hex(binary);
        std::cout << "Hexadecimal representation: " << hex << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}