#include "rectangle.h"


Figure::Point Rectangle::getGeometricCenter() const {
    Figure::Point center;
    
    center.x = (vertices[0].x + vertices[2].x) / 2.0;
    center.y = (vertices[0].y + vertices[2].y) / 2.0;
    return center;
}


double Rectangle::calculateArea() const {
    
    double width = std::sqrt(
        std::pow(vertices[1].x - vertices[0].x, 2) + 
        std::pow(vertices[1].y - vertices[0].y, 2)
    );
    double height = std::sqrt(
        std::pow(vertices[3].x - vertices[0].x, 2) + 
        std::pow(vertices[3].y - vertices[0].y, 2)
    );
    return width * height;
}


Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 4, vertices);
    }
    return *this;
}


Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        std::copy(other.vertices, other.vertices + 4, vertices);
    }
    return *this;
}


Figure& Rectangle::operator=(const Figure& other) {
    if (const Rectangle* r = dynamic_cast<const Rectangle*>(&other)) {
        *this = *r;
    }
    return *this;
}

Figure& Rectangle::operator=(Figure&& other) noexcept {
    if (Rectangle* r = dynamic_cast<Rectangle*>(&other)) {
        *this = std::move(*r);
    }
    return *this;
}


bool Rectangle::operator==(const Figure& other) const {
    if (const Rectangle* r = dynamic_cast<const Rectangle*>(&other)) {
        for (int i = 0; i < 4; ++i) {
            if (vertices[i].x != r->vertices[i].x || 
                vertices[i].y != r->vertices[i].y)
                return false;
        }
        return true;
    }
    return false;
}


std::istream& operator>>(std::istream& is, Rectangle& rectangle) {
    for (int i = 0; i < 4; ++i) {
        is >> rectangle.vertices[i].x >> rectangle.vertices[i].y;
    }
    return is;
}


void Rectangle::printCoordinates(std::ostream& os) const {
    os << "Координаты вершин прямоугольника:\n";
    for (int i = 0; i < 4; ++i) {
        os << "Вершина " << i + 1 << ": (" 
           << vertices[i].x << ", " 
           << vertices[i].y << ")\n";
    }
}