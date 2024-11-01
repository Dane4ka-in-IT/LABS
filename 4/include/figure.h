#pragma once
#include "point.h"
#include <memory>
#include <vector>
#include <string>

template<Scalar T>
class Figure {
protected:
    std::vector<std::unique_ptr<Point<T>>> vertices_;

public:
    // Конструктор по умолчанию
    Figure() = default;
    
    // Виртуальный деструктор
    virtual ~Figure() = default;

    // Конструктор копирования
    Figure(const Figure& other) {
        for (const auto& vertex : other.vertices_) {
            vertices_.push_back(std::make_unique<Point<T>>(vertex->x(), vertex->y()));
        }
    }
    
    // Оператор присваивания копированием
    Figure& operator=(const Figure& other) {
        if (this != &other) {
            vertices_.clear();
            for (const auto& vertex : other.vertices_) {
                vertices_.push_back(std::make_unique<Point<T>>(vertex->x(), vertex->y()));
            }
        }
        return *this;
    }
    
    // Оператор присваивания перемещением
    Figure& operator=(Figure&& other) noexcept {
        if (this != &other) {
            vertices_ = std::move(other.vertices_);
        }
        return *this;
    }

    // Чисто виртуальные методы
    virtual Point<T> getCenter() const = 0;
    virtual double getArea() const = 0;
    virtual std::unique_ptr<Figure<T>> clone() const = 0;
    virtual std::string getName() const = 0;
    
    // Оператор приведения к double
    operator double() const {
        return getArea();
    }
    
    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Figure<T>& figure) {
        for (const auto& vertex : figure.vertices_) {
            os << *vertex << " ";
        }
        return os;
    }
};