#include <iostream>
#include <vector>
#include <memory>
#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"

int main() {
    
    std::vector<std::unique_ptr<Figure>> figures;
    
    
    std::cout << "Введите координаты квадрата (4 вершины, x y):\n";
    auto square = std::make_unique<Square>();
    std::cin >> *square;
    figures.push_back(std::move(square));

    
    std::cout << "Введите координаты прямоугольника (4 вершины, x y):\n";
    auto rectangle = std::make_unique<Rectangle>();
    std::cin >> *rectangle;
    figures.push_back(std::move(rectangle));

    
    std::cout << "Введите координаты трапеции (4 вершины, x y):\n";
    auto trapezoid = std::make_unique<Trapezoid>();
    std::cin >> *trapezoid;
    figures.push_back(std::move(trapezoid));

    
    std::cout << "\nИнформация о фигурах:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "\nФигура " << i << ":\n";
        std::cout << *figures[i];
        auto center = figures[i]->getGeometricCenter();
        std::cout << "Геометрический центр: (" << center.x << ", " << center.y << ")\n";
        std::cout << "Площадь: " << static_cast<double>(*figures[i]) << "\n";
    }

    
    double totalArea = 0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    std::cout << "\nОбщая площадь всех фигур: " << totalArea << "\n";

    
    std::cout << "\nВведите индекс фигуры для удаления: ";
    size_t index;
    std::cin >> index;
    if (index < figures.size()) {
        figures.erase(figures.begin() + index);
        std::cout << "Фигура удалена\n";
    } else {
        std::cout << "Неверный индекс\n";
    }

    
    std::cout << "\nОставшиеся фигуры:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "\nФигура " << i << ":\n";
        std::cout << *figures[i];
    }

    return 0;
}