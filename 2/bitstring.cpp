#include "bitstring.h"
#include <stdexcept>
#include <algorithm>
#include <cstring>

BitString::BitString() : data(nullptr), length(0) {}

BitString::BitString(const std::string& t) : length(t.length()) {
    data = new unsigned char[length];
    for (size_t i = 0; i < length; ++i) {
        if (t[i] != '0' && t[i] != '1') {
            throw std::invalid_argument("String must contain only '0' and '1'");
        }
        data[i] = t[i] - '0';
    }
}

BitString::BitString(const BitString& other) : length(other.length) {
    data = new unsigned char[length];
    std::copy(other.data, other.data + length, data);
}

BitString::BitString(BitString&& other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}

BitString::~BitString() noexcept {
    delete[] data;
}

BitString& BitString::operator=(const BitString& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new unsigned char[length];
        std::copy(other.data, other.data + length, data);
    }
    return *this;
}

BitString& BitString::operator=(BitString&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}

BitString BitString::operator+(const BitString& other) const {
    size_t resultLength = std::max(length, other.length) + 1;  
    std::string initialValue(resultLength, '0');
    BitString result(initialValue);
    unsigned char carry = 0;
    for (size_t i = 0; i < resultLength - 1; ++i) {
        unsigned char sum = carry + 
                            (i < length ? data[length - 1 - i] : 0) + 
                            (i < other.length ? other.data[other.length - 1 - i] : 0);
        result.data[resultLength - 1 - i] = sum % 2;
        carry = sum / 2;
    }
    result.data[0] = carry;

    
    size_t firstNonZero = 0;
    while (firstNonZero < resultLength - 1 && result.data[firstNonZero] == 0) {
        ++firstNonZero;
    }
    if (firstNonZero > 0) {
        std::string trimmedValue(resultLength - firstNonZero, '0');
        BitString trimmedResult(trimmedValue);
        std::copy(result.data + firstNonZero, result.data + resultLength, trimmedResult.data);
        return trimmedResult;
    }

    return result;
}

BitString BitString::operator-(const BitString& other) const {
    if (*this < other) {
        throw std::runtime_error("Cannot subtract a larger BitString from a smaller one");
    }
    std::string initialValue(length, '0');
    BitString result(initialValue);
    int borrow = 0;
    for (size_t i = 0; i < length; ++i) {
        int diff = data[i] - (i < other.length ? other.data[i] : 0) - borrow;
        if (diff < 0) {
            diff += 2;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.data[i] = diff;
    }
    return result;
}

BitString& BitString::operator+=(const BitString& other) {
    *this = *this + other;
    return *this;
}

BitString& BitString::operator-=(const BitString& other) {
    *this = *this - other;
    return *this;
}

bool BitString::operator>(const BitString& other) const {
    if (length != other.length) {
        return length > other.length;
    }
    for (size_t i = length; i-- > 0; ) {
        if (data[i] != other.data[i]) {
            return data[i] > other.data[i];
        }
    }
    return false;
}

bool BitString::operator<(const BitString& other) const {
    if (length != other.length) {
        return length < other.length;
    }
    for (size_t i = 0; i < length; ++i) {
        if (data[i] != other.data[i]) {
            return data[i] < other.data[i];
        }
    }
    return false;
}

bool BitString::operator==(const BitString& other) const {
    if (length != other.length) {
        return false;
    }
    return std::memcmp(data, other.data, length) == 0;
}

BitString BitString::operator&(const BitString& other) const {
    size_t resultLength = std::min(length, other.length);
    std::string initialValue(resultLength, '0');
    BitString result(initialValue);
    for (size_t i = 0; i < resultLength; ++i) {
        result.data[resultLength - 1 - i] = data[length - 1 - i] & other.data[other.length - 1 - i];
    }
    return result;
}

BitString BitString::operator|(const BitString& other) const {
    size_t resultLength = std::max(length, other.length);
    std::string initialValue(resultLength, '0');
    BitString result(initialValue);
    for (size_t i = 0; i < resultLength; ++i) {
        result.data[i] = (i < length ? data[i] : 0) | (i < other.length ? other.data[i] : 0);
    }
    return result;
}

BitString BitString::operator^(const BitString& other) const {
    size_t resultLength = std::max(length, other.length);
    std::string initialValue(resultLength, '0');
    BitString result(initialValue);
    for (size_t i = 0; i < resultLength; ++i) {
        result.data[resultLength - 1 - i] = 
            (i < length ? data[length - 1 - i] : 0) ^ 
            (i < other.length ? other.data[other.length - 1 - i] : 0);
    }
    return result;
}

BitString BitString::operator~() const {
    std::string initialValue(length, '0');
    BitString result(initialValue);
    for (size_t i = 0; i < length; ++i) {
        result.data[i] = data[i] ? 0 : 1;
    }
    return result;
}

size_t BitString::size() const {
    return length;
}

unsigned char BitString::get(size_t index) const {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void BitString::set(size_t index, unsigned char value) {
    if (index >= length) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value ? 1 : 0;
}