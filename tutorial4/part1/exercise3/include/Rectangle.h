#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <iostream>
namespace Geometry {
    class Rectangle {
        private:
            double _width;
            double _height;

        public:
            double width() const { return _width;}
            double height() const { return _height;}
            Rectangle(double width, double height);
            explicit Rectangle(double side_length);
            Rectangle() = default;
            double area() const;

    };
} // namespace Geometry
#endif /* RECTANGLE_H */