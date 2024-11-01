#pragma once
#include <iostream>

// Базовый класс для геометрических фигур
class Figure {
protected:
    // Структура для хранения точек
    struct Point {
        double x, y;
    };

public:
    virtual ~Figure() = default;
    
    // Основные методы для работы с фигурами
    virtual Point getGeometricCenter() const = 0;
    virtual double calculateArea() const = 0;
    virtual void printCoordinates(std::ostream& os) const = 0;
    
    // Операторы для работы с фигурами
    virtual bool operator==(const Figure& other) const = 0;
    virtual Figure& operator=(const Figure& other) = 0;
    virtual Figure& operator=(Figure&& other) noexcept = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig) {
        fig.printCoordinates(os);
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Figure& fig);

    // Оператор приведения к double для получения площади
    operator double() const { return calculateArea(); }
};