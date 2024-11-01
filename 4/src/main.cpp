#include <iostream>
#include <sstream>
#include "array.h"
#include "pentagon.h"
#include "hexagon.h"
#include "octagon.h"

int main() {
    
    Array<std::shared_ptr<Figure<double>>> figures;
    
    
    auto pentagon = std::make_shared<Pentagon<double>>();
    auto hexagon = std::make_shared<Hexagon<double>>();
    auto octagon = std::make_shared<Octagon<double>>();
    
    
    std::stringstream pentagon_input("0 0 2 0 3 2 1 3 -1 2");
    std::stringstream hexagon_input("0 0 2 0 3 2 2 4 0 4 -1 2");
    std::stringstream octagon_input("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    
    pentagon_input >> *pentagon;
    hexagon_input >> *hexagon;
    octagon_input >> *octagon;
    
    figures.push_back(pentagon);
    figures.push_back(hexagon);
    figures.push_back(octagon);
    
    
    std::cout << "\nИнформация о фигурах:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << "\nФигура " << i + 1 << " (" << figures[i]->getName() << "):\n";
        std::cout << "Координаты: " << *figures[i];
        std::cout << "\nЦентр: " << figures[i]->getCenter();
        std::cout << "\nПлощадь: " << static_cast<double>(*figures[i]) << "\n";
    }
    
    
    double total_area = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total_area += static_cast<double>(*figures[i]);
    }
    std::cout << "\nОбщая площадь всех фигур: " << total_area << "\n";
    
    
    figures.remove(1);
    std::cout << "\nПосле удаления второй фигуры:\n";
    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << figures[i]->getName() << " ";
    }
    std::cout << "\n";
    
    
    Array<Pentagon<double>> pentagons;
    Pentagon<double> p1, p2;
    std::stringstream p1_input("0 0 2 0 3 2 1 3 -1 2");
    std::stringstream p2_input("1 1 3 1 4 3 2 4 0 3");
    p1_input >> p1;
    p2_input >> p2;
    
    pentagons.push_back(p1);
    pentagons.push_back(p2);
    
    std::cout << "\nРабота с массивом пятиугольников:\n";
    for (size_t i = 0; i < pentagons.size(); ++i) {
        std::cout << "Пятиугольник " << i + 1 << ": " << pentagons[i];
        std::cout << "\nПлощадь: " << static_cast<double>(pentagons[i]) << "\n";
    }
    
    return 0;
}