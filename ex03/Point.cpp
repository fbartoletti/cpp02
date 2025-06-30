#include "Point.hpp"
#include "Fixed.hpp"

// ✅ Default constructor
Point::Point() : x(0), y(0) {
}

// ✅ Constructor with two floats that initializes x and y
Point::Point(float const x_val, float const y_val) : x(x_val), y(y_val) {
}

Point::Point(const Point& src) : x(src.x), y(src.y) {
}

// ✅ Copy constructor
Point::~Point() {
}

// ✅ Assignment operator (although limited for const attributes)
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
