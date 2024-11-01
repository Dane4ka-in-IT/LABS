#pragma once
#include "figure.h"
#include <cmath>

// Шаблонный класс для представления правильного пятиугольника
template<Scalar T>
class Pentagon : public Figure<T> {
public:
    // Конструктор по умолчанию инициализирует вершины нулями
    Pentagon() {
        // Создаем 5 вершин с нулевыми координатами
        for (size_t i = 0; i < 5; ++i) {
            this->vertices_.push_back(std::make_unique<Point<T>>(0, 0));
        }
    }
    
    // Конструктор копирования
    Pentagon(const Pentagon& other) : Figure<T>(other) {}
    
    // Оператор присваивания копированием
    Pentagon& operator=(const Pentagon& other) {
        if (this != &other) {
            Figure<T>::operator=(other);
        }
        return *this;
    }
    
    // Оператор присваивания перемещением
    Pentagon& operator=(Pentagon&& other) noexcept {
        if (this != &other) {
            Figure<T>::operator=(std::move(other));
        }
        return *this;
    }
    
    // Создание копии фигуры
    std::unique_ptr<Figure<T>> clone() const override {
        return std::make_unique<Pentagon<T>>(*this);
    }
    
    // Вычисление геометрического центра
    Point<T> getCenter() const override {
        T x_sum = 0, y_sum = 0;
        // Суммируем координаты всех вершин
        for (const auto& vertex : this->vertices_) {
            x_sum += vertex->x();
            y_sum += vertex->y();
        }
        // Возвращаем точку с усредненными координатами
        return Point<T>(x_sum / 5, y_sum / 5);
    }
    
    // Вычисление площади методом треугольников
    double getArea() const override {
        double area = 0;
        // Используем формулу площади через координаты вершин
        for (size_t i = 0; i < 5; ++i) {
            size_t j = (i + 1) % 5;
            area += (this->vertices_[i]->x() * this->vertices_[j]->y() -
                    this->vertices_[j]->x() * this->vertices_[i]->y());
        }
        return std::abs(area) / 2.0;
    }
    
    // Оператор ввода для чтения координат вершин
    friend std::istream& operator>>(std::istream& is, Pentagon<T>& pentagon) {
        for (size_t i = 0; i < 5; ++i) {
            T x, y;
            is >> x >> y;
            pentagon.vertices_[i] = std::make_unique<Point<T>>(x, y);
        }
        return is;
    }
    
    // Получение имени фигуры
    std::string getName() const override {
        return "Пятиугольник";
    }
    
    // Оператор сравнения
    bool operator==(const Pentagon& other) const {
        for (size_t i = 0; i < 5; ++i) {
            if (this->vertices_[i]->x() != other.vertices_[i]->x() ||
                this->vertices_[i]->y() != other.vertices_[i]->y()) {
                return false;
            }
        }
        return true;
    }
};