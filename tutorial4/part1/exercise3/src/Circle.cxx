#include "Circle.h"
namespace Geometry {
    Circle::Circle(double radius) : _radius{radius} {
    if (_radius < 0){
        std::cout << "Are you sure you wanted a circle with negative radius?\n";
    }
    }
    double Circle::area() const { return M_PI * _radius * _radius; }
    double Circle::radius() const {return _radius;}
}