#include "trapezoid.h"


Figure::Point Trapezoid::getGeometricCenter() const {
    Figure::Point center;
    
    double sumX = 0, sumY = 0;
    for (int i = 0; i < 4; ++i) {
        sumX += vertices[i].x;
        sumY += vertices[i].y;
    }
    center.x = sumX / 4.0;
    center.y = sumY / 4.0;
    return center;
}


double Trapezoid::calculateArea() const {
    
    double x1 = vertices[0].x, y1 = vertices[0].y;
    double x2 = vertices[1].x, y2 = vertices[1].y;
    double x3 = vertices[2].x, y3 = vertices[2].y;
    double x4 = vertices[3].x, y4 = vertices[3].y;
    
    
    return std::abs(
        (x1 * y2 + x2 * y3 + x3 * y4 + x4 * y1) -
        (y1 * x2 + y2 * x3 + y3 * x4 + y4 * x1)
    ) / 2.0;
}


Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 4, vertices);
    }
    return *this;
}


Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 4, vertices);
    }
    return *this;
}


Figure& Trapezoid::operator=(const Figure& other) {
    if (const Trapezoid* t = dynamic_cast<const Trapezoid*>(&other)) {
        *this = *t;
    }
    return *this;
}

Figure& Trapezoid::operator=(Figure&& other) noexcept {
    if (Trapezoid* t = dynamic_cast<Trapezoid*>(&other)) {
        *this = std::move(*t);
    }
    return *this;
}


bool Trapezoid::operator==(const Figure& other) const {
    if (const Trapezoid* t = dynamic_cast<const Trapezoid*>(&other)) {
        for (int i = 0; i < 4; ++i) {
            if (vertices[i].x != t->vertices[i].x || 
                vertices[i].y != t->vertices[i].y)
                return false;
        }
        return true;
    }
    return false;
}


std::istream& operator>>(std::istream& is, Trapezoid& trapezoid) {
    for (int i = 0; i < 4; ++i) {
        is >> trapezoid.vertices[i].x >> trapezoid.vertices[i].y;
    }
    return is;
}


void Trapezoid::printCoordinates(std::ostream& os) const {
    os << "Координаты вершин трапеции:\n";
    for (int i = 0; i < 4; ++i) {
        os << "Вершина " << i + 1 << ": (" 
           << vertices[i].x << ", " 
           << vertices[i].y << ")\n";
    }
}