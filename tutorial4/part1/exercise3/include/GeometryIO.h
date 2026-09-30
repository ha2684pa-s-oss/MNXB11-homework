#ifndef GEOMETRY_IO
#define GEOMETRY_IO

#include "Rectangle.h"
#include "Circle.h"
#include <iostream>
namespace Geometry {
// I'm not a huge fan of using the >> operator in this way because it requires
// that you have a Rectangle/Circle object already
std::istream &operator>>(std::istream &input_stream, Rectangle &rectangle);
std::istream &operator>>(std::istream &input_stream, Circle &circle);
std::ostream &operator<<(std::ostream &output_stream, const Rectangle &rectangle);
std::ostream &operator<<(std::ostream &output_stream, const Circle &circle);
} // namespace Geometry

#endif /* GEOMETRY_IO */