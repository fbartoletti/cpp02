#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	//fixed point number
	int value;
	//fractional part bits
	static const int fractionalBits;
public:
	Fixed();
	//int costructor
	Fixed(const int n);
	//float costructor
	Fixed(const float n);
	//copy costructor
	Fixed(const Fixed& src);
	//copy operator
	Fixed& operator=(const Fixed& rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
