#include "Fixed.hpp"

const int Fixed::fractionalBits = 8;

Fixed::Fixed() : value(0) {
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	// std::cout << "Int constructor called" << std::endl;
	value = n << fractionalBits;
}

Fixed::Fixed(const float n) {
	// std::cout << "Float constructor called" << std::endl;
	value = roundf(n * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed& src) {
	// std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed() {
	// std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->value = rhs.getRawBits();
	}
	return *this;
}

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

int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return (float)value / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return value >> fractionalBits;
}

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

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
