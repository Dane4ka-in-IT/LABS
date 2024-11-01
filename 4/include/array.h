#pragma once
#include <memory>
#include <stdexcept>

template<class T>
class Array {
private:
    size_t size_;
    size_t capacity_;
    std::shared_ptr<T[]> data_;

    void resize(size_t new_capacity) {
        auto new_data = std::shared_ptr<T[]>(new T[new_capacity]);
        for (size_t i = 0; i < size_; ++i) {
            new_data[i] = std::move(data_[i]);
        }
        data_ = std::move(new_data);
        capacity_ = new_capacity;
    }

public:
    // Конструктор по умолчанию
    Array() : size_(0), capacity_(1), data_(new T[1]) {}
    
    // Конструктор копирования
    Array(const Array& other) : size_(other.size_), capacity_(other.capacity_) {
        data_ = std::shared_ptr<T[]>(new T[capacity_]);
        for (size_t i = 0; i < size_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    
    // Оператор присваивания копированием
    Array& operator=(const Array& other) {
        if (this != &other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = std::shared_ptr<T[]>(new T[capacity_]);
            for (size_t i = 0; i < size_; ++i) {
                data_[i] = other.data_[i];
            }
        }
        return *this;
    }
    
    // Оператор присваивания перемещением
    Array& operator=(Array&& other) noexcept {
        if (this != &other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            data_ = std::move(other.data_);
            other.size_ = 0;
            other.capacity_ = 0;
        }
        return *this;
    }
    
    // Добавление элемента в конец массива
    void push_back(const T& value) {
        if (size_ == capacity_) {
            resize(capacity_ * 2);
        }
        data_[size_++] = value;
    }
    
    // Удаление элемента по индексу
    void remove(size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size_ - 1; ++i) {
            data_[i] = std::move(data_[i + 1]);
        }
        --size_;
    }
    
    // Оператор доступа к элементу
    T& operator[](size_t index) {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    
    // Константный оператор доступа к элементу
    const T& operator[](size_t index) const {
        if (index >= size_) {
            throw std::out_of_range("Index out of range");
        }
        return data_[index];
    }
    
    // Получение размера массива
    size_t size() const {
        return size_;
    }
    
    // Получение емкости массива
    size_t capacity() const {
        return capacity_;
    }
};