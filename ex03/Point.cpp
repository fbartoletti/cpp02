#include "Point.hpp"
//#include "Fixed.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(float const x_val, float const y_val) : x(x_val), y(y_val) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {
}

Point::~Point() {
}

Point& Point::operator=(const Point& rhs) {
	(void)rhs;
	return *this;
}

Fixed Point::getX() const {
	return this->x;
}

Fixed Point::getY() const {
	return this->y;
}
