#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int fractionalBits;
public:
	Fixed();
	Fixed(const int n);
	Fixed(const float n);
	Fixed(const Fixed& src);
	Fixed& operator=(const Fixed& rhs);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
