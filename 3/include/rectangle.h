#pragma once
#include "figure.h"
#include <cmath>

// Класс для представления прямоугольника
class Rectangle : public Figure {
private:
    Point vertices[4];  // Массив вершин прямоугольника (по часовой стрелке)

public:
    Rectangle() = default;
    
    // Реализация методов базового класса
    Point getGeometricCenter() const override;
    double calculateArea() const override;
    void printCoordinates(std::ostream& os) const override;
    
    // Операторы для работы с прямоугольником
    Rectangle& operator=(const Rectangle& other);
    Rectangle& operator=(Rectangle&& other) noexcept;
    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;
    
    // Ввод/вывод координат вершин
    friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
};