#pragma once
#include "figure.h"
#include <cmath>

// Шаблонный класс для представления правильного шестиугольника
template<Scalar T>
class Hexagon : public Figure<T> {
public:
    // Конструктор по умолчанию
    Hexagon() {
        // Инициализируем 6 вершин нулевыми координатами
        for (size_t i = 0; i < 6; ++i) {
            this->vertices_.push_back(std::make_unique<Point<T>>(0, 0));
        }
    }
    
    // Конструктор копирования
    Hexagon(const Hexagon& other) : Figure<T>(other) {}
    
    // Оператор присваивания копированием
    Hexagon& operator=(const Hexagon& other) {
        Figure<T>::operator=(other);
        return *this;
    }
    
    // Оператор присваивания перемещением
    Hexagon& operator=(Hexagon&& other) noexcept {
        Figure<T>::operator=(std::move(other));
        return *this;
    }
    
    // Создание копии фигуры
    std::unique_ptr<Figure<T>> clone() const override {
        auto new_hexagon = std::make_unique<Hexagon<T>>();
        for (size_t i = 0; i < this->vertices_.size(); ++i) {
            new_hexagon->vertices_[i] = std::make_unique<Point<T>>(
                this->vertices_[i]->x(),
                this->vertices_[i]->y()
            );
        }
        return new_hexagon;
    }
    
    // Вычисление геометрического центра
    Point<T> getCenter() const override {
        T x_sum = 0;
        T y_sum = 0;
        for (const auto& vertex : this->vertices_) {
            x_sum += vertex->x();
            y_sum += vertex->y();
        }
        return Point<T>(x_sum / 6, y_sum / 6);
    }
    
    // Вычисление площади методом треугольников
    double getArea() const override {
        double area = 0;
        for (size_t i = 0; i < 6; ++i) {
            size_t j = (i + 1) % 6;
            area += this->vertices_[i]->x() * this->vertices_[j]->y();
            area -= this->vertices_[j]->x() * this->vertices_[i]->y();
        }
        return std::abs(area) / 2.0;
    }
    
    // Ввод координат вершин
    friend std::istream& operator>>(std::istream& is, Hexagon<T>& hexagon) {
        for (size_t i = 0; i < 6; ++i) {
            T x, y;
            is >> x >> y;
            hexagon.vertices_[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }
    
    // Получение имени фигуры
    std::string getName() const override {
        return "Шестиугольник";
    }
};