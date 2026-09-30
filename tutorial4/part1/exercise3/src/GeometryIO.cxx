#include "GeometryIO.h"
namespace Geometry {
std::istream &operator>>(std::istream &input_stream, Rectangle &rectangle) {
  double width{};
  double height{};
  input_stream >> width;
  input_stream >> height;
  // Width and height are private member variables of the rectangle class.
  // Assuming we can't add a way to change them, this is one way you can get
  // around that
  Rectangle temporary{width, height};
  rectangle = temporary;
  return input_stream;
}

std::istream &operator>>(std::istream &input_stream, Circle &circle) {
  double radius{};
  input_stream >> radius;
  Circle temporary{radius};
  circle = temporary;
  return input_stream;
}
std::ostream &operator<<(std::ostream &output_stream,
                         const Rectangle &rectangle) {
  output_stream << "Rectangle with width " << rectangle.width()
                << " and height " << rectangle.height();
  return output_stream;
}
std::ostream &operator<<(std::ostream &output_stream, const Circle &circle) {
  output_stream << "Circle with radius " << circle.radius();
  return output_stream;
}
} // namespace Geometry