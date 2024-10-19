#ifndef BINARY_TO_HEX_H
#define BINARY_TO_HEX_H

#include <string>
#include <stdexcept>

std::string binary_to_hex(const std::string& binary) {
    if (binary.empty()) {
        return "";
    }

    // Проверка на валидность входной строки
    for (char c : binary) {
        if (c != '0' && c != '1') {
            throw std::invalid_argument("Input string must contain only 0 and 1");
        }
    }

    std::string hex = "";
    int len = binary.length();
    
    // Добавляем ведущие нули, если длина не кратна 4
    std::string padded_binary = std::string(4 - len % 4, '0') + binary;
    
    // Конвертируем каждые 4 бита в шестнадцатеричную цифру
    for (int i = 0; i < padded_binary.length(); i += 4) {
        int value = 0;
        for (int j = 0; j < 4; ++j) {
            value = value * 2 + (padded_binary[i + j] - '0');
        }
        hex += (value < 10) ? (char)(value + '0') : (char)(value - 10 + 'A');
    }

    return hex;
}

#endif // BINARY_TO_HEX_H