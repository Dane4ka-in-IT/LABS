#include <gtest/gtest.h>
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include "../include/array.h"
#include <sstream>

// Тесты для Pentagon
TEST(PentagonTest, CenterCalculation) {
    Pentagon<double> pentagon;
    std::stringstream ss("0 0 2 0 3 2 1 3 -1 2");
    ss >> pentagon;
    
    auto center = pentagon.getCenter();
    EXPECT_NEAR(center.x(), 1.0, 0.0001);
    EXPECT_NEAR(center.y(), 1.4, 0.0001);
}

TEST(PentagonTest, AreaCalculation) {
    Pentagon<double> pentagon;
    std::stringstream ss("0 0 2 0 3 2 1 3 -1 2");
    ss >> pentagon;
    
    double area = static_cast<double>(pentagon);
    EXPECT_NEAR(area, 8.0, 0.0001);
}

// Тесты для Hexagon
TEST(HexagonTest, CenterCalculation) {
    Hexagon<double> hexagon;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> hexagon;
    
    auto center = hexagon.getCenter();
    EXPECT_NEAR(center.x(), 1.0, 0.0001);
    EXPECT_NEAR(center.y(), 2.0, 0.0001);
}

TEST(HexagonTest, AreaCalculation) {
    Hexagon<double> hexagon;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> hexagon;
    
    double area = static_cast<double>(hexagon);
    EXPECT_NEAR(area, 12.0, 0.0001);
}

TEST(HexagonTest, Equality) {
    Hexagon<double> h1, h2;
    std::stringstream ss1("0 0 2 0 3 2 2 4 0 4 -1 2");
    std::stringstream ss2("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss1 >> h1;
    ss2 >> h2;
    
    EXPECT_TRUE(h1 == h2);
}

// Тесты для Octagon
TEST(OctagonTest, CenterCalculation) {
    Octagon<double> octagon;
    std::stringstream ss("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    ss >> octagon;
    
    auto center = octagon.getCenter();
    EXPECT_NEAR(center.x(), 1.0, 0.0001);
    EXPECT_NEAR(center.y(), 2.0, 0.0001);
}

TEST(OctagonTest, AreaCalculation) {
    Octagon<double> octagon;
    std::stringstream ss("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    ss >> octagon;
    
    double area = static_cast<double>(octagon);
    EXPECT_NEAR(area, 14.0, 0.0001);
}

TEST(OctagonTest, Equality) {
    Octagon<double> o1, o2;
    std::stringstream ss1("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    std::stringstream ss2("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    ss1 >> o1;
    ss2 >> o2;
    
    EXPECT_TRUE(o1 == o2);
}

// Тесты для операций копирования и перемещения
TEST(OperationsTest, CopyAssignmentHexagon) {
    Hexagon<double> h1;
    std::stringstream ss("0 0 2 0 3 2 2 4 0 4 -1 2");
    ss >> h1;
    
    Hexagon<double> h2;
    h2 = h1;
    EXPECT_TRUE(h1 == h2);
}

TEST(OperationsTest, MoveAssignmentOctagon) {
    Octagon<double> o1;
    std::stringstream ss("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    ss >> o1;
    
    Octagon<double> o2;
    o2 = std::move(o1);
    
    Octagon<double> expected;
    std::stringstream ss2("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    ss2 >> expected;
    EXPECT_TRUE(o2 == expected);
}

// Тест для Array с разными типами фигур
TEST(ArrayTest, MixedFigures) {
    Array<std::shared_ptr<Figure<double>>> figures;
    
    auto pentagon = std::make_shared<Pentagon<double>>();
    auto hexagon = std::make_shared<Hexagon<double>>();
    auto octagon = std::make_shared<Octagon<double>>();
    
    std::stringstream ss1("0 0 2 0 3 2 1 3 -1 2");
    std::stringstream ss2("0 0 2 0 3 2 2 4 0 4 -1 2");
    std::stringstream ss3("0 0 2 0 3 1 3 3 2 4 0 4 -1 3 -1 1");
    
    ss1 >> *pentagon;
    ss2 >> *hexagon;
    ss3 >> *octagon;
    
    figures.push_back(pentagon);
    figures.push_back(hexagon);
    figures.push_back(octagon);
    
    EXPECT_EQ(figures.size(), 3);
    double total_area = 0;
    for (size_t i = 0; i < figures.size(); ++i) {
        total_area += static_cast<double>(*figures[i]);
    }
    EXPECT_NEAR(total_area, 34.0, 0.0001);
}