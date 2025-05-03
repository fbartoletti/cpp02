#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

class Point {
private:
	Fixed const x;
	Fixed const y;

public:
	Point();
	Point(float const x, float const y);
	Point(const Point& src);
	~Point();

	Point& operator=(const Point& rhs);
	Fixed getX() const;
	Fixed getY() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
