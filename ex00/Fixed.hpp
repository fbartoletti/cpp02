#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int value;
	static const int fractionalBits;
public:
	// ✅ Orthodox Canonical Form
	Fixed();
	Fixed(const Fixed& rhs);
	Fixed& operator=(const Fixed& rhs);
	~Fixed();

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
