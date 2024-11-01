#pragma once
#include "figure.h"
#include <cmath>

// Класс для представления квадрата
class Square : public Figure {
private:
    Point vertices[4];  // Массив вершин квадрата (по часовой стрелке)

public:
    Square() = default;
    
    // Реализация методов базового класса
    Point getGeometricCenter() const override;
    double calculateArea() const override;
    void printCoordinates(std::ostream& os) const override;
    
    // Операторы для работы с квадратом
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;
    
    // Ввод/вывод координат вершин
    friend std::istream& operator>>(std::istream& is, Square& square);
};