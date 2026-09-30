// main.cxx
#include "Rectangle.h"
#include "Circle.h"
#include "GeometryIO.h"
#include <iostream>
int main() {
    std::cout << "Please enter the width and height of a rectangle\n";
    Geometry::Rectangle r{};
    std::cin >> r;
    std::cout << "The rectangle: " << r << " has area: " << r.area() << std::endl;
    std::cout << "Please enter the radius of a circle\n";
    Geometry::Circle c{};
    std::cin >> c;
    std::cout << "The circle: " << c << " has area: " << c.area() << std::endl;
    return 0;
}