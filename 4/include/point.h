#pragma once
#include <concepts>
#include <iostream>

// Концепт для проверки скалярного типа
template<typename T>
concept Scalar = std::is_arithmetic_v<T>;

// Шаблонный класс для представления точки на плоскости
template<Scalar T>
class Point {
private:
    T x_; // координата по оси X
    T y_; // координата по оси Y

public:
    // Конструкторы
    Point() : x_(0), y_(0) {}
    Point(T x, T y) : x_(x), y_(y) {}
    
    // Методы доступа к координатам
    T x() const noexcept { return x_; }
    T y() const noexcept { return y_; }

    // Перегрузка операторов ввода/вывода
    friend std::ostream& operator<<(std::ostream& os, const Point<T>& point) {
        os << "(" << point.x_ << ", " << point.y_ << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Point<T>& point) {
        is >> point.x_ >> point.y_;
        return is;
    }
};