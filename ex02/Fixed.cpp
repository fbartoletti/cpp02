#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

// ✅ Costructor
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// ✅ Int costructor
Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	value = n << fractionalBits;
}

// ✅ Float costructor
Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	value = roundf(n * (1 << fractionalBits));
}

// ✅ Copy costructor
Fixed::Fixed(const Fixed& src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

// ✅ Distructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// ✅ Copy assignment operator
Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return *this;
}

// ✅ Comparison operators
bool Fixed::operator>(const Fixed& rhs) const {
	return this->value > rhs.value;
}

bool Fixed::operator<(const Fixed& rhs) const {
	return this->value < rhs.value;
}

bool Fixed::operator>=(const Fixed& rhs) const {
	return this->value >= rhs.value;
}

bool Fixed::operator<=(const Fixed& rhs) const {
	return this->value <= rhs.value;
}

bool Fixed::operator==(const Fixed& rhs) const {
	return this->value == rhs.value;
}

bool Fixed::operator!=(const Fixed& rhs) const {
	return this->value != rhs.value;
}

// ✅ Arithmetic operators
Fixed Fixed::operator+(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->value + rhs.value);
	return result;
}

Fixed Fixed::operator-(const Fixed& rhs) const {
	Fixed result;
	result.setRawBits(this->value - rhs.value);
	return result;
}

Fixed Fixed::operator*(const Fixed& rhs) const {
	Fixed result;
	long long temp = (long long)this->value * (long long)rhs.value;
	result.setRawBits(temp >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed& rhs) const {
	Fixed result;
	if (rhs.value == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
		return *this;
	}
	long long temp = ((long long)this->value << fractionalBits) / rhs.value;
	result.setRawBits(temp);
	return result;
}

// ✅ Increment/Decrement Operators
Fixed& Fixed::operator++() {
	++this->value;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed& Fixed::operator--() {
	--this->value;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

// ✅ Methods to manipulate the value
int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

// ✅ Convert to float
float Fixed::toFloat(void) const {
	return (float)value / (1 << fractionalBits);
}

// ✅ Convert to int
int Fixed::toInt(void) const {
	return value >> fractionalBits;
}

// ✅ Static functions for min/max
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// ✅ Insertion operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
