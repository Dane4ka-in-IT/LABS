#include <iostream>
#include <string>
#include "replace_letters.h"

int main() {
    std::string text;
    int n;
    char old_value, new_value;

    std::cout << "Введите текст: ";
    std::getline(std::cin, text);

    std::cout << "Введите n: ";
    std::cin >> n;

    std::cout << "Введите символ для замены: ";
    std::cin >> old_value;

    std::cout << "Введите новый символ: ";
    std::cin >> new_value;

    std::string result = replaceLetters(text, n, old_value, new_value);

    std::cout << "Результат: " << result << std::endl;

    return 0;
}
//♪┏(・o･)┛♪┗ ( ･o･) ┓♪