#include "Fixed.hpp"

// Inizializzazione del membro statico
const int Fixed::fractionalBits = 8;

// Default constructor
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Int costructor
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	value = n << fractionalBits;
}

// Float constructor
Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(n * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->value = rhs.getRawBits();
	return *this;
}

// Distructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return(float)value / (1 < fractionalBits);
}

int Fixed::toInt(void) const {
	return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
