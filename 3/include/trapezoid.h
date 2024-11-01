#pragma once
#include "figure.h"
#include <cmath>

// Класс для представления трапеции
class Trapezoid : public Figure {
private:
    Point vertices[4];  // Массив вершин трапеции (по часовой стрелке)

public:
    Trapezoid() = default;
    
    // Реализация методов базового класса
    Point getGeometricCenter() const override;
    double calculateArea() const override;
    void printCoordinates(std::ostream& os) const override;
    
    // Операторы для работы с трапецией
    Trapezoid& operator=(const Trapezoid& other);
    Trapezoid& operator=(Trapezoid&& other) noexcept;
    Figure& operator=(const Figure& other) override;
    Figure& operator=(Figure&& other) noexcept override;
    bool operator==(const Figure& other) const override;
    
    // Ввод/вывод координат вершин
    friend std::istream& operator>>(std::istream& is, Trapezoid& trapezoid);
};