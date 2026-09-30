// Circle.h 
#ifndef CIRCLE_H
#define CIRCLE_H
#include <cmath>
#include <iostream>
namespace Geometry {
class Circle {
private:
  double _radius;
public:
  Circle() = default;
  explicit Circle(double radius);
  double area() const;
  double radius() const;
};
} // namespace Geometry
#endif /* CIRCLE_H */