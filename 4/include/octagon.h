#pragma once
#include "figure.h"
#include <cmath>

// Шаблонный класс для представления правильного восьмиугольника
template<Scalar T>
class Octagon : public Figure<T> {
public:
    // Конструктор по умолчанию
    Octagon() {
        // Инициализируем 8 вершин нулевыми координатами
        for (size_t i = 0; i < 8; ++i) {
            this->vertices_.push_back(std::make_unique<Point<T>>(0, 0));
        }
    }
    
    // Конструктор копирования
    Octagon(const Octagon& other) : Figure<T>(other) {}
    
    // Оператор присваивания копированием
    Octagon& operator=(const Octagon& other) {
        Figure<T>::operator=(other);
        return *this;
    }
    
    // Оператор присваивания перемещением
    Octagon& operator=(Octagon&& other) noexcept {
        Figure<T>::operator=(std::move(other));
        return *this;
    }
    
    // Создание копии фигуры
    std::unique_ptr<Figure<T>> clone() const override {
        auto new_octagon = std::make_unique<Octagon<T>>();
        for (size_t i = 0; i < this->vertices_.size(); ++i) {
            new_octagon->vertices_[i] = std::make_unique<Point<T>>(
                this->vertices_[i]->x(),
                this->vertices_[i]->y()
            );
        }
        return new_octagon;
    }
    
    // Вычисление геометрического центра
    Point<T> getCenter() const override {
        T x_sum = 0;
        T y_sum = 0;
        for (const auto& vertex : this->vertices_) {
            x_sum += vertex->x();
            y_sum += vertex->y();
        }
        return Point<T>(x_sum / 8, y_sum / 8);
    }
    
    // Вычисление площади методом треугольников
    double getArea() const override {
        double area = 0;
        for (size_t i = 0; i < 8; ++i) {
            size_t j = (i + 1) % 8;
            area += this->vertices_[i]->x() * this->vertices_[j]->y();
            area -= this->vertices_[j]->x() * this->vertices_[i]->y();
        }
        return std::abs(area) / 2.0;
    }
    
    // Ввод координат вершин
    friend std::istream& operator>>(std::istream& is, Octagon<T>& octagon) {
        for (size_t i = 0; i < 8; ++i) {
            T x, y;
            is >> x >> y;
            octagon.vertices_[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }
    
    // Получение имени фигуры
    std::string getName() const override {
        return "Восьмиугольник";
    }
};