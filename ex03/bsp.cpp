#include "Point.hpp"
#include "Fixed.hpp"

// ✅ Auxiliary function to calculate the area of ​​a triangle
static Fixed calculateArea(Point const& p1, Point const& p2, Point const& p3) {
	Fixed area = ((p1.getX() * (p2.getY() - p3.getY())) +
				 (p2.getX() * (p3.getY() - p1.getY())) +
				 (p3.getX() * (p1.getY() - p2.getY()))) / Fixed(2);
	if (area < Fixed(0))
		area = area * Fixed(-1);

	return area;
}

// ✅ Main bsp function
bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = calculateArea(a, b, c);
	Fixed areaPAB = calculateArea(point, a, b);
	Fixed areaPBC = calculateArea(point, b, c);
	Fixed areaPAC = calculateArea(point, a, c);
	// ✅ Check if the point is on an edge or vertex
	if (areaPAB == Fixed(0) || areaPBC == Fixed(0) || areaPAC == Fixed(0) || areaABC == Fixed(0))
		return false;
	Fixed sumAreas = areaPAB + areaPBC + areaPAC;
	Fixed epsilon(0.01f);
	Fixed diff = sumAreas - areaABC;
	// ✅ Tolerance check for rounding errors
	if (diff < epsilon && diff > Fixed(-0.01f))
		return true;

	return false;
}
