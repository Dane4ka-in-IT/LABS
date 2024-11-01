#include <gtest/gtest.h>
#include "../include/square.h"
#include "../include/rectangle.h"
#include "../include/trapezoid.h"
#include <sstream>

// Тесты для Square
TEST(SquareTest, CenterCalculation) {
    Square square;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> square;
    
    auto center = square.getGeometricCenter();
    EXPECT_NEAR(center.x, 1.0, 0.0001);
    EXPECT_NEAR(center.y, 1.0, 0.0001);
}

TEST(SquareTest, AreaCalculation) {
    Square square;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> square;
    
    double area = static_cast<double>(square);
    EXPECT_NEAR(area, 4.0, 0.0001);
}

TEST(SquareTest, Equality) {
    Square s1, s2;
    std::stringstream ss1("0 0 2 0 2 2 0 2");
    std::stringstream ss2("0 0 2 0 2 2 0 2");
    ss1 >> s1;
    ss2 >> s2;
    
    EXPECT_TRUE(s1 == s2);
}

// Тесты для Rectangle
TEST(RectangleTest, CenterCalculation) {
    Rectangle rectangle;
    std::stringstream ss("0 0 3 0 3 2 0 2");
    ss >> rectangle;
    
    auto center = rectangle.getGeometricCenter();
    EXPECT_NEAR(center.x, 1.5, 0.0001);
    EXPECT_NEAR(center.y, 1.0, 0.0001);
}

TEST(RectangleTest, AreaCalculation) {
    Rectangle rectangle;
    std::stringstream ss("0 0 3 0 3 2 0 2");
    ss >> rectangle;
    
    double area = static_cast<double>(rectangle);
    EXPECT_NEAR(area, 6.0, 0.0001);
}

TEST(RectangleTest, Equality) {
    Rectangle r1, r2;
    std::stringstream ss1("0 0 3 0 3 2 0 2");
    std::stringstream ss2("0 0 3 0 3 2 0 2");
    ss1 >> r1;
    ss2 >> r2;
    
    EXPECT_TRUE(r1 == r2);
}

// Тесты для Trapezoid
TEST(TrapezoidTest, CenterCalculation) {
    Trapezoid trapezoid;
    std::stringstream ss("0 0 4 0 3 2 1 2");  // Трапеция с основаниями 4 и 2
    ss >> trapezoid;
    
    auto center = trapezoid.getGeometricCenter();
    EXPECT_NEAR(center.x, 2.0, 0.0001);
    EXPECT_NEAR(center.y, 1.0, 0.0001);
}

TEST(TrapezoidTest, AreaCalculation) {
    Trapezoid trapezoid;
    std::stringstream ss("0 0 4 0 3 2 1 2");
    ss >> trapezoid;
    
    double area = static_cast<double>(trapezoid);
    EXPECT_NEAR(area, 6.0, 0.0001);
}

TEST(TrapezoidTest, Equality) {
    Trapezoid t1, t2;
    std::stringstream ss1("0 0 4 0 3 2 1 2");
    std::stringstream ss2("0 0 4 0 3 2 1 2");
    ss1 >> t1;
    ss2 >> t2;
    
    EXPECT_TRUE(t1 == t2);
}

// Тесты для операций копирования и перемещения
TEST(OperationsTest, CopyAssignment) {
    Square s1;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> s1;
    
    Square s2;
    s2 = s1;
    EXPECT_TRUE(s1 == s2);
}

TEST(OperationsTest, MoveAssignment) {
    Square s1;
    std::stringstream ss("0 0 2 0 2 2 0 2");
    ss >> s1;
    
    Square s2;
    s2 = std::move(s1);
    
    Square expected;
    std::stringstream ss2("0 0 2 0 2 2 0 2");
    ss2 >> expected;
    EXPECT_TRUE(s2 == expected);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}